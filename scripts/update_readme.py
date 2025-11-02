#!/usr/bin/env python3
"""
Update README.md's "Problems & status" section from testcases.json.

- Creates a comprehensive single table with all problems
- Shows ID, problem name, category, difficulty, test cases, implementation links, and videos
- Includes category filter section for easy navigation
- Links directly to source code implementations in C++, Go, and Java

Heuristic replacement:
- Replaces from the line starting with '## Problems & status' up to (but not including)
  the line starting with '### Categories'. If '### Categories' is missing, replaces to EOF.
"""

import json
import os
import re
from glob import glob
from typing import Dict, List, Tuple

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
README_PATH = os.path.join(REPO_ROOT, "README.md")
TESTCASES_PATH = os.path.join(REPO_ROOT, "testcases.json")
NEETCODE_PATH = os.path.join(REPO_ROOT, "scripts", "neetcode_links.json")


def load_testcases(path: str) -> Dict[str, dict]:
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def load_neetcode_links(path: str) -> Dict[str, str]:
    try:
        with open(path, "r", encoding="utf-8") as f:
            data = json.load(f)
            # normalize keys to strings
            return {str(k): v for k, v in data.items() if v}
    except FileNotFoundError:
        return {}


def detect_languages(repo_root: str, category: str, pid: str) -> List[str]:
    langs: List[str] = []
    cpp_glob = os.path.join(repo_root, "src", "cpp", category, f"{pid}.*.cpp")
    go_glob = os.path.join(repo_root, "src", "go", category, f"{pid}.*.go")
    java_glob = os.path.join(repo_root, "src", "java", category, f"{pid}.*.java")
    
    # Special case for Java DP files which use P{ID}.java format
    if category == "dp":
        java_special = os.path.join(repo_root, "src", "java", category, f"P{pid}.java")
        if os.path.exists(java_special):
            langs.append("Java")
        elif glob(java_glob):
            langs.append("Java")
    else:
        if glob(java_glob):
            langs.append("Java")
    
    if glob(cpp_glob):
        langs.append("C++")
    if glob(go_glob):
        langs.append("Go")
    return langs


def build_single_table_section(cases: Dict[str, dict], neetcode_map: Dict[str, str]) -> str:
    # Helper function for implementation paths in details
    def get_impl_path_for_details(lang: str, ext: str, cat: str, pid_str: str) -> str:
        if lang.lower() == "java" and cat == "dp":
            return f"src/java/{cat}/P{pid_str}.java"
        else:
            # Find the actual file name
            pattern = f"src/{lang.lower()}/{cat}/{pid_str}.*{ext}"
            files = glob(os.path.join(REPO_ROOT, pattern))
            if files:
                return os.path.relpath(files[0], REPO_ROOT).replace(os.sep, "/")
            return f"src/{lang.lower()}/{cat}/{pid_str}.{ext}"

    # Collect all problems
    problems: List[Tuple[int, str, str, str, int, List[str], str, str, str]] = []
    by_cat: Dict[str, List[int]] = {}  # category -> list of problem IDs for filtering
    
    for pid_str, spec in cases.items():
        try:
            pid = int(pid_str)
        except ValueError:
            continue
        cat = spec.get("category", "misc")
        title = spec.get("description", f"Problem {pid_str}")
        case_count = len(spec.get("cases", []))
        langs = detect_languages(REPO_ROOT, cat, pid_str)
        difficulty = spec.get("difficulty", "-")
        url = spec.get("url", "")
        video = spec.get("video") or neetcode_map.get(pid_str, "")
        
        problems.append((pid, pid_str, title, cat, case_count, langs, difficulty, url, video))
        by_cat.setdefault(cat, []).append(pid)

    # Sort problems by ID
    problems.sort(key=lambda x: x[0])
    
    # Build the main table
    lines = [
        "## Problems & status",
        "",
        f"All {len(problems)} problems implemented across C++, Go, and Java. Use `./run -l` to list problems, `./run -c <category>` to run by category.",
        "",
        "_Click problem ID to view LeetCode problem description (opens in new tab). Click ✓ to view source code. Click 📺 for NeetCode explanation videos._",
        "",
        "| ID | Problem | Category | Difficulty | Test Cases | C++ | Go | Java | NeetCode Explanation Video |",
        "|---:|---|---|---|---:|---|---|---|---|"
    ]
    
    for pid, pid_str, title, cat, case_count, langs, difficulty, url, video in problems:
        # Build implementation links
        def get_impl_path(lang: str, ext: str) -> str:
            if lang.lower() == "java" and cat == "dp":
                # Special case for Java DP files which use P{ID}.java format
                return f"src/java/{cat}/P{pid_str}.java"
            else:
                # Find the actual file name
                pattern = f"src/{lang.lower()}/{cat}/{pid_str}.*{ext}"
                files = glob(os.path.join(REPO_ROOT, pattern))
                if files:
                    return os.path.relpath(files[0], REPO_ROOT).replace(os.sep, "/")
                return f"src/{lang.lower()}/{cat}/{pid_str}.{ext}"
        
        # ID column links to LeetCode problem page (opens in new tab)
        if url:
            # Ensure the URL has the /description/ suffix for better UX
            leetcode_url = url
            if not leetcode_url.endswith('/description/'):
                if leetcode_url.endswith('/'):
                    leetcode_url += 'description/'
                else:
                    leetcode_url += '/description/'
            id_cell = f'<a href="{leetcode_url}" target="_blank">{pid_str}</a>'
        else:
            id_cell = pid_str
        
        # Individual language links
        cpp_link = f"[✓]({get_impl_path('cpp', 'cpp')})" if "C++" in langs else "-"
        go_link = f"[✓]({get_impl_path('go', 'go')})" if "Go" in langs else "-"
        java_link = f"[✓]({get_impl_path('java', 'java')})" if "Java" in langs else "-"
        
        # Video link
        video_cell = f"[📺]({video})" if video else "-"
        
        lines.append(f"| {id_cell} | {title} | {cat} | {difficulty.title()} | {case_count} | {cpp_link} | {go_link} | {java_link} | {video_cell} |")
    
    # Add category filter section
    lines.extend(["", "### Filter by Category"])
    for cat in sorted(by_cat.keys()):
        pids = sorted(by_cat[cat])
        pid_links = ", ".join([f"[{pid}](#{pid})" for pid in pids])
        lines.append(f"- **{cat}**: {pid_links}")
    
    lines.extend([
        "",
        "> Use `./run -c <category>` to test problems by category. Problem counts reflect `testcases.json` entries.",
        "",
        "---",
        "",
        "## 📋 Problem Details",
        "",
        "_Click to expand individual problem descriptions, examples, and test cases._",
        ""
    ])
    
    # Add collapsible details for each problem
    for pid, pid_str, title, cat, case_count, langs, difficulty, url, video in problems:
        spec = cases[pid_str]
        problem_cases = spec.get("cases", [])
        
        lines.append(f'<details>')
        lines.append(f'<summary><strong>LC{pid}: {title}</strong> ({difficulty.title()}) - {cat}</summary>')
        lines.append(f'')
        
        # Problem link
        if url:
            lines.append(f'**🔗 Problem Link**: {url}')
            lines.append(f'')
        
        # Video link
        if video:
            lines.append(f'**📺 NeetCode Explanation**: {video}')
            lines.append(f'')
        
        # Implementation links  
        lines.append(f'**💻 Solutions**:')
        if "C++" in langs:
            cpp_path = get_impl_path_for_details('cpp', 'cpp', cat, pid_str)
            lines.append(f'- [C++]({cpp_path})')
        if "Go" in langs:
            go_path = get_impl_path_for_details('go', 'go', cat, pid_str)
            lines.append(f'- [Go]({go_path})')
        if "Java" in langs:
            java_path = get_impl_path_for_details('java', 'java', cat, pid_str)
            lines.append(f'- [Java]({java_path})')
        lines.append(f'')
        
        # Test cases
        if problem_cases:
            lines.append(f'**🧪 Test Cases** ({len(problem_cases)} cases):')
            for i, case in enumerate(problem_cases[:3], 1):  # Show first 3 cases
                case_str = str(case).replace("'", '"')[:100]  # Truncate long cases
                if len(str(case)) > 100:
                    case_str += "..."
                lines.append(f'{i}. `{case_str}`')
            if len(problem_cases) > 3:
                lines.append(f'   ... and {len(problem_cases) - 3} more cases')
            lines.append(f'')
        
        lines.append(f'</details>')
        lines.append(f'')
    
    lines.extend([
        "> Use `./run -c <category>` to test problems by category. Problem counts reflect `testcases.json` entries."
    ])
    
    return "\n".join(lines) + "\n"


def replace_section_in_readme(readme_text: str, new_section: str) -> str:
    # Find start of the section
    start_pat = re.compile(r"^## Problems \& status\s*$", re.M)
    start_m = start_pat.search(readme_text)
    if not start_m:
        # If not found, append to the end with a separator
        return readme_text.rstrip() + "\n\n" + new_section

    start_idx = start_m.start()

    # Find the next heading after this section to know where to stop
    after_text = readme_text[start_m.end():]
    end_m = re.search(r"^### Categories\s*$", after_text, re.M)
    if end_m:
        end_idx = start_m.end() + end_m.start()
    else:
        end_idx = len(readme_text)

    return readme_text[:start_idx] + new_section + readme_text[end_idx:]


def main() -> None:
    cases = load_testcases(TESTCASES_PATH)
    neetcode_map = load_neetcode_links(NEETCODE_PATH)
    section = build_single_table_section(cases, neetcode_map)
    with open(README_PATH, "r", encoding="utf-8") as f:
        readme = f.read()
    updated = replace_section_in_readme(readme, section)
    if updated != readme:
        with open(README_PATH, "w", encoding="utf-8") as f:
            f.write(updated)
        print("README.md updated.")
    else:
        print("README.md already up to date.")


if __name__ == "__main__":
    main()
