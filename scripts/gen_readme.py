#!/usr/bin/env python3
import argparse
import json
import os
import re
from collections import defaultdict

RE_PROBLEM_DIR = re.compile(r"^(\d+)\.([a-z0-9\-]+)$")

HEADER_STATIC = """# LeetCode Solutions

This repository contains categorized solutions to LeetCode problems. Each problem is organized in its own directory under a category (such as `array`, `linked_list`, `sliding_window`, `two_pointers`, etc.), and may include multiple solution approaches (e.g., using different data structures or algorithms).

## Repository Structure

```
<category>/
    <problem-id>.<problem-name>/cpp/
        solution-<approach>.cpp
        Makefile
        ...
```
"""

USAGE_STATIC = """
## Features
- **Multiple Approaches:** Each problem may have several solution files, demonstrating different techniques (e.g., map, set, vector).
- **Category Organization:** Problems are grouped by topic for easy navigation.
- **Makefile Automation:** Each problem and category includes a Makefile for easy building and testing.
- **Standardized Test Output:** All solutions use a common test utility for readable, aligned output.

## How to Use
1. **Clone the repository:**
     ```bash
     git clone https://github.com/rajeshkumarblr/mylc.git
     cd mylc
     ```
2. **Build and run a solution:**
     ```bash
     cd array/1.two-sum/cpp
     make
     ./solution
     ```
     Or for problems with multiple solutions:
     ```bash
     cd sliding_window/3.longest-substring-without-repeating-characters/cpp
     make
     ./solution-map
     ./solution-set
     ./solution-vector
     ```
3. **Add your own solutions:**
     - Create a new directory for the problem under the appropriate category.
     - Add your solution file(s) and a Makefile.
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

def scan_repo(repo_root: str):
    by_cat = defaultdict(list)
    for category in sorted(os.listdir(repo_root)):
        cat_path = os.path.join(repo_root, category)
        if not os.path.isdir(cat_path):
            continue
        if category.startswith('.') or category in {"scripts", ".git", ".github"}:
            continue
        for entry in sorted(os.listdir(cat_path)):
            full = os.path.join(cat_path, entry)
            if not os.path.isdir(full):
                continue
            m = RE_PROBLEM_DIR.match(entry)
            if not m:
                continue
            pid, slug = m.group(1), m.group(2)
            by_cat[category].append((pid, slug))
    return by_cat

def enrich(by_cat, tags_map):
    enriched = {}
    for cat, items in by_cat.items():
        rows = []
        for pid, slug in items:
            key = f"{pid}.{slug}"
            meta = tags_map.get(key, {})
            title = meta.get("title", slug.replace("-", " ").title())
            difficulty = meta.get("difficulty", "Unknown")
            tags = meta.get("tags", [])
            rows.append({
                "id": int(pid),
                "id_str": pid,
                "slug": slug,
                "title": title,
                "difficulty": difficulty,
                "tags": tags,
                "path": f"{cat}/{pid}.{slug}/",
                "leetcode": f"https://leetcode.com/problems/{slug}/"
            })
        rows.sort(key=lambda r: r["id"])  # sort by ID within category
        enriched[cat] = rows
    return enriched

def render_problems(enriched):
    lines = ["## Problems\n"]
    # category sections
    for cat in sorted(enriched.keys()):
        lines.append(f"### {cat}\n")
        for r in enriched[cat]:
            tags_txt = ", ".join(r["tags"]) if r["tags"] else ""
            tags_part = f" — tags: {tags_txt}" if tags_txt else ""
            lines.append(f"- [{r['id_str']}. {r['title']}]({r['leetcode']}) — *{r['difficulty']}*{tags_part} — path: `{r['path']}`")
        lines.append("")  # blank line between categories
    return "\n".join(lines)

def build_readme(repo_root: str):
    tags = load_tags_json(repo_root)
    by_cat = scan_repo(repo_root)
    enriched = enrich(by_cat, tags)
    problems_md = render_problems(enriched)
    readme = "\n".join([HEADER_STATIC, problems_md, USAGE_STATIC])
    return readme

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
