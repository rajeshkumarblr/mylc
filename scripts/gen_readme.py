#!/usr/bin/env python3
import argparse
import json
import os
import re
from collections import defaultdict

RE_PROBLEM_FILE = re.compile(r"^lc(\d+)\.cpp$")
RE_URL_SLUG = re.compile(r"https?://leetcode\.com/problems/([a-z0-9\-]+)/", re.I)
RE_LC_ID = re.compile(r"@lc\s+app=leetcode\s+id=(\d+)\s+lang=cpp", re.I)
RE_TITLE_BRACKET = re.compile(r"^\s*\[\s*(\d+)\s*\]\s*([^\n\r]+)", re.I)

HEADER_STATIC = """# LeetCode Solutions

This repository contains categorized solutions to LeetCode problems. Each problem is organized in its own directory under a category (such as `array`, `linked_list`, `sliding_window`, `two_pointers`, etc.).

## Repository Structure

```
<category>/
    lc<id>.cpp
    lc<id2>.cpp
    Makefile
    ...
```
Each problem has a single C++ file (e.g., `lc3.cpp`) containing all solution variants for that problem.
"""

USAGE_STATIC = """
## Features
- **Multiple Approaches:** Each problem may have several solution variants, all in a single file (e.g., different methods in `lc3.cpp`).
- **Category Organization:** Problems are grouped by topic for easy navigation.
- **Makefile Automation:** Each category includes a Makefile for easy building and testing.
- **Standardized Test Output:** All C++ solutions use a common test utility for readable, aligned output.

## How to Use
1. **Clone the repository:**
    ```bash
    git clone https://github.com/rajeshkumarblr/mylc.git
    cd mylc
    ```
2. **Build and run a C++ solution:**
    ```bash
    cd array
    make lc1
    ./build/lc1
    ```
    Or for other problems:
    ```bash
    cd sliding_window
    make lc3
    ./build/lc3
    ```
3. **Add your own solutions:**
    - Add a new file (e.g., `lc42.cpp`) in the appropriate category directory.
    - Add your solution variants as methods in that file.
    - Use the provided `lc_test_utils.h` for standardized test output.

## Categories
- `array/` — Array and math problems
- `linked_list/` — Linked list problems
- `sliding_window/` — Sliding window techniques
- `two_pointers/` — Two pointers and related problems
- *(Add more categories as needed)*

## Contributing
Pull requests are welcome! Please follow the directory and naming conventions, and use the test utilities for consistency.

## License
This project is licensed under the MIT License.
"""

def load_tags_json(repo_root: str):
    path = os.path.join(repo_root, "tags.json")
    if not os.path.exists(path):
        return {}
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

def read_text_safe(path: str) -> str:
    try:
        with open(path, "r", encoding="utf-8", errors="ignore") as f:
            return f.read()
    except Exception:
        return ""

def extract_meta_from_cpp(filepath: str):
    text = read_text_safe(filepath)
    meta = {}
    m = RE_URL_SLUG.search(text)
    if m:
        meta["slug"] = m.group(1).strip().lower()
    m = RE_TITLE_BRACKET.search(text)
    if m:
        meta["id"] = m.group(1).strip()
        meta["title"] = m.group(2).strip()
    m = RE_LC_ID.search(text)
    if m:
        meta["id"] = m.group(1).strip()
    if "title" not in meta and "slug" in meta:
        meta["title"] = meta["slug"].replace("-", " ").title()
    return meta

def scan_repo(repo_root: str):
    by_cat = defaultdict(list)
    for category in sorted(os.listdir(repo_root)):
        cat_path = os.path.join(repo_root, category)
        if not os.path.isdir(cat_path):
            continue
        if category.startswith('.') or category in {"scripts", ".git", ".github", "build", ".vscode"}:
            continue
        for entry in sorted(os.listdir(cat_path)):
            m = RE_PROBLEM_FILE.match(entry)
            if not m:
                continue
            pid = m.group(1)
            filepath = os.path.join(cat_path, entry)
            file_meta = extract_meta_from_cpp(filepath)
            by_cat[category].append((pid, entry, file_meta))
    return by_cat

def enrich(by_cat, tags_map):
    enriched = {}
    id_to_meta = {}
    for key, meta in tags_map.items():
        if '.' in key:
            pid, slug = key.split('.', 1)
            id_to_meta.setdefault(pid, []).append((meta, slug))
    for cat, items in by_cat.items():
        rows = []
        for pid, filename, file_meta in items:
            meta, slug = None, None
            if pid in id_to_meta:
                meta, slug = id_to_meta[pid][0]
            title = (meta.get("title") if meta and "title" in meta else None) or file_meta.get("title") or filename
            difficulty = meta.get("difficulty") if meta and "difficulty" in meta else "Unknown"
            tags = meta.get("tags") if meta and "tags" in meta else []
            final_slug = slug or file_meta.get("slug")
            leetcode_url = f"https://leetcode.com/problems/{final_slug}/" if final_slug else ""
            rows.append({
                "id": int(pid),
                "id_str": pid,
                "filename": filename,
                "title": title,
                "difficulty": difficulty,
                "tags": tags,
                "path": f"{cat}/{filename}",
                "leetcode": leetcode_url
            })
        rows.sort(key=lambda r: r["id"])
        enriched[cat] = rows
    return enriched

def render_problems(enriched):
    lines = ["## Problems\n"]
    for cat in sorted(enriched.keys()):
        lines.append(f"### {cat}\n")
        for r in enriched[cat]:
            tags_txt = ", ".join(r["tags"]) if r["tags"] else ""
            tags_part = f" — tags: {tags_txt}" if tags_txt else ""
            title_md = f"[{r['title']}]({r['leetcode']})" if r["leetcode"] else r["title"]
            lines.append(f"- [{r['id_str']}] {title_md} — *{r['difficulty']}*{tags_part} — file: `{r['path']}`")
        lines.append("")
    return "\n".join(lines)

def build_readme(repo_root: str):
    tags = load_tags_json(repo_root)
    by_cat = scan_repo(repo_root)
    enriched = enrich(by_cat, tags)
    problems_md = render_problems(enriched)
    return "\n".join([HEADER_STATIC, problems_md, USAGE_STATIC])

def main():
    parser = argparse.ArgumentParser(description="Generate README.md with dynamic Problems section and links.")
    parser.add_argument("--repo-root", default=".", help="Repo root (default: current dir)")
    parser.add_argument("--output", default="README.md", help="Output README path")
    args = parser.parse_args()
    readme = build_readme(args.repo_root)
    out_path = os.path.join(args.repo_root, args.output)
    with open(out_path, "w", encoding="utf-8") as f:
        f.write(readme)
    print(f"Wrote {args.output}.")

if __name__ == "__main__":
    main()
