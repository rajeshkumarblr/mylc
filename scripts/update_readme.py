#!/usr/bin/env python3
"""
Update README.md's "Problems & status" section from testcases.json.

- Groups problems by category
- Generates collapsible <details> blocks per category
- Shows problem id, title, test case count, and available languages (C++/Go) based on src/* presence

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
    if glob(cpp_glob):
        langs.append("C++")
    if glob(go_glob):
        langs.append("Go")
    if glob(java_glob):
        langs.append("Java")
    return langs


def build_collapsible_section(cases: Dict[str, dict], neetcode_map: Dict[str, str]) -> str:
    # Build cat -> list of (id_int, id_str, title, case_count, languages, difficulty, url, video)
    by_cat: Dict[str, List[Tuple[int, str, str, int, List[str], str, str, str]]] = {}
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
        by_cat.setdefault(cat, []).append((pid, pid_str, title, case_count, langs, difficulty, url, video))

    # Sort categories alpha, problems by id
    lines: List[str] = ["## Problems & status", "Expand a category to view its problems.", ""]
    for cat in sorted(by_cat.keys()):
        items = sorted(by_cat[cat], key=lambda x: x[0])
        count = len(items)
        lines.append("<details>")
        lines.append(f"<summary><strong>{cat}</strong> ({count})</summary>\n")
        lines.append("| # | Problem | Diff | Test cases | Languages | Video |")
        lines.append("|---:|---|:---:|---:|---|---|")
        for _, pid_s, title, ncases, langs, diff, url, video in items:
            langs_txt = ", ".join(langs) if langs else "-"
            num_cell = f"[{pid_s}]({url})" if url else pid_s
            video_cell = f"[link]({video})" if video else "-"
            lines.append(f"| {num_cell} | {title} | {diff.title()} | {ncases} | {langs_txt} | {video_cell} |")
        lines.append("\n</details>\n")

    lines.append("> Counts reflect entries in `testcases.json`. If you add/modify cases there, re-run `./run -l` to inspect.")
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
    section = build_collapsible_section(cases, neetcode_map)
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
