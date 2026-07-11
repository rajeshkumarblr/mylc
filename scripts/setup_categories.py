import os
import json
import re

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CPP_DIR = os.path.join(REPO_ROOT, "src", "cpp")

CATEGORY_MAP = {
    '1-D Dynamic Programming': 'dp',
    '2-D Dynamic Programming': 'dp',
    'Advanced Graphs': 'graphs',
    'Arrays & Hashing': 'hash',
    'Backtracking': 'backtracking',
    'Binary Search': 'binary_search',
    'Bit Manipulation': 'bit_manipulation',
    'Graphs': 'graphs',
    'Greedy': 'greedy',
    'Heap / Priority Queue': 'heap',
    'Intervals': 'intervals',
    'Linked List': 'list',
    'Math & Geometry': 'math',
    'Sliding Window': 'sliding_window',
    'Stack': 'stack',
    'Trees': 'tree',
    'Tries': 'trie',
    'Two Pointers': 'two_pointer'
}

def main():
    with open(os.path.join(REPO_ROOT, "scripts", "neetcode_flat.json"), "r") as f:
        problems = json.load(f)
        
    with open(os.path.join(REPO_ROOT, "scripts", "neetcode_signatures.json"), "r") as f:
        signatures = json.load(f)

    with open(os.path.join(REPO_ROOT, "testcases.json"), "r") as f:
        testcases = json.load(f)

    # 1. Generate Boilerplates
    generated = 0
    used_categories = set()
    for p in problems:
        pid = str(p["id"])
        slug = p["slug"]
        name = p["name"]
        nc_cat = p["category"]
        diff = p["difficulty"]
        url = p.get("url", f"https://leetcode.com/problems/{slug}/")
        
        folder = CATEGORY_MAP.get(nc_cat, "misc")
        used_categories.add(folder)
        
        # Update testcases category
        if pid not in testcases:
            testcases[pid] = {
                "category": folder,
                "description": name,
                "difficulty": diff.lower(),
                "url": url,
                "cases": []
            }
        else:
            testcases[pid]["category"] = folder
            
        target_dir = os.path.join(CPP_DIR, folder)
        os.makedirs(target_dir, exist_ok=True)
        
        # Don't overwrite if it already exists (e.g., solved problems)
        target_path = os.path.join(target_dir, f"{pid}.{slug}.cpp")
        if not os.path.exists(target_path) or p.get("existing_path") is None:
            # It's an unsolved problem or a missing file
            sig = signatures.get(pid, "class Solution {\npublic:\n    // TODO: Implement solution\n};")
            
            content = f"""/*
 * @lc app=leetcode id={pid} lang=cpp
 *
 * [{pid}] {name}
 *
 * Difficulty: {diff}
 * Category: {folder}
 * URL: {url}
 */

#include "../lc_test_utils.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

// @lc code=start
{sig.strip()}
// @lc code=end
"""
            with open(target_path, "w", encoding="utf-8") as f:
                f.write(content)
            generated += 1

    # 2. Save testcases.json
    with open(os.path.join(REPO_ROOT, "testcases.json"), "w", encoding="utf-8") as f:
        json.dump(testcases, f, indent=2)

    # 3. Update Makefile
    makefile_path = os.path.join(CPP_DIR, "Makefile")
    with open(makefile_path, "r") as f:
        makefile = f.read()

    # Find existing CATEGORY_DIRS
    match = re.search(r"CATEGORY_DIRS := (.*)", makefile)
    if match:
        existing_cats = set(match.group(1).split())
        all_cats = existing_cats.union(used_categories)
        new_line = "CATEGORY_DIRS := " + " ".join(sorted(all_cats))
        makefile = makefile.replace(match.group(0), new_line)
        
        with open(makefile_path, "w") as f:
            f.write(makefile)

    print(f"Generated {generated} C++ boilerplates.")
    print("Updated testcases.json and Makefile.")

if __name__ == "__main__":
    main()
