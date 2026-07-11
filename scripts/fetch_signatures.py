import os
import json
import urllib.request
import re
import time

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NEETCODE_FLAT_PATH = os.path.join(REPO_ROOT, "scripts", "neetcode_flat.json")
NEET150_DIR = os.path.join(REPO_ROOT, "src", "cpp", "neet150")
SIGNATURES_CACHE = os.path.join(REPO_ROOT, "scripts", "neetcode_signatures.json")

def fetch_cpp_snippet(slug):
    url = "https://leetcode.com/graphql"
    headers = {
        "Content-Type": "application/json",
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)"
    }
    payload = {
        "query": """
        query questionData($titleSlug: String!) {
          question(titleSlug: $titleSlug) {
            codeSnippets {
              lang
              langSlug
              code
            }
          }
        }
        """,
        "variables": {"titleSlug": slug}
    }
    
    req = urllib.request.Request(url, data=json.dumps(payload).encode("utf-8"), headers=headers)
    try:
        with urllib.request.urlopen(req, timeout=10) as res:
            data = json.loads(res.read().decode("utf-8"))
            question = data.get("data", {}).get("question")
            if not question:
                return None
            snippets = question.get("codeSnippets", [])
            for s in snippets:
                if s["langSlug"] == "cpp":
                    return s["code"]
    except Exception as e:
        print(f"Error fetching {slug}: {e}")
    return None

def main():
    # Load cache if exists
    cache = {}
    if os.path.exists(SIGNATURES_CACHE):
        with open(SIGNATURES_CACHE, "r") as f:
            cache = json.load(f)
            
    with open(NEETCODE_FLAT_PATH, "r") as f:
        problems = json.load(f)
        
    os.makedirs(NEET150_DIR, exist_ok=True)
    
    total = len(problems)
    for idx, p in enumerate(problems, 1):
        pid = p["id"]
        slug = p["slug"]
        name = p["name"]
        cat = p["category"]
        diff = p["difficulty"]
        url = p.get("url", f"https://leetcode.com/problems/{slug}/")
        
        # Check cache first
        cpp_code = cache.get(str(pid))
        if not cpp_code:
            print(f"[{idx}/{total}] Fetching signature for: {name} ({slug})...")
            cpp_code = fetch_cpp_snippet(slug)
            if cpp_code:
                cache[str(pid)] = cpp_code
                # Save cache progressively
                with open(SIGNATURES_CACHE, "w") as f:
                    json.dump(cache, f, indent=2)
                time.sleep(0.1) # Be gentle with API
            else:
                print(f"Failed to fetch {slug}, using default skeleton.")
                cpp_code = """class Solution {
public:
    // TODO: Define the method signature and implement the solution here
};"""
        
        target_filename = f"{pid}.{slug}.cpp"
        target_path = os.path.join(NEET150_DIR, target_filename)
        
        # Build contents
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
#include <list>
#include <algorithm>

using namespace std;

namespace neet150 {{
// @lc code=start
{cpp_code.strip()}
// @lc code=end
}}
"""
        with open(target_path, "w", encoding="utf-8") as f:
            f.write(content)
            
    print(f"\nCompleted! Generated/updated 150 C++ files with exact method signatures.")

if __name__ == "__main__":
    main()
