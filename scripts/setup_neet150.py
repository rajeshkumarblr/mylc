import os
import json
import shutil

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NEETCODE_FLAT_PATH = os.path.join(REPO_ROOT, "scripts", "neetcode_flat.json")
NEET150_DIR = os.path.join(REPO_ROOT, "src", "cpp", "neet150")

def main():
    # Re-create neet150 directory clean
    if os.path.exists(NEET150_DIR):
        shutil.rmtree(NEET150_DIR)
    os.makedirs(NEET150_DIR, exist_ok=True)
    
    with open(NEETCODE_FLAT_PATH, "r") as f:
        problems = json.load(f)
        
    generated_count = 0
    
    for p in problems:
        pid = p["id"]
        slug = p["slug"]
        name = p["name"]
        cat = p["category"]
        diff = p["difficulty"]
        url = p.get("url", "")
        
        target_filename = f"{pid}.{slug}.cpp"
        target_path = os.path.join(NEET150_DIR, target_filename)
        
        write_boilerplate(target_path, pid, name, cat, diff, url)
        generated_count += 1
            
    print(f"\nExecution Complete:")
    print(f"Total problems processed: {len(problems)}")
    print(f"Generated namespaced boilerplates: {generated_count}")

def write_boilerplate(path, pid, name, cat, diff, url):
    content = f"""/*
 * @lc app=leetcode id={pid} lang=cpp
 *
 * [{pid}] {name}
 *
 * Difficulty: {diff}
 * Category: {cat}
 * URL: {url}
 */

#include "../lc_test_utils.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

namespace neet150 {{
// @lc code=start
class Solution {{
public:
    // TODO: Define the method signature and implement the solution here
}};
// @lc code=end
}}
"""
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)

if __name__ == "__main__":
    main()
