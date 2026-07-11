import json
import os
import glob
import re

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CPP_DIR = os.path.join(REPO_ROOT, "src", "cpp")

def main():
    # 1. Load leetcode all problems
    try:
        with open(os.path.join(REPO_ROOT, "scripts", "leetcode-all-problems.json"), "r") as f:
            lc = json.load(f)
    except Exception as e:
        print(f"Error loading leetcode-all-problems.json: {e}")
        return

    # Convert LC to a slug -> description map
    slug_to_desc = {}
    if isinstance(lc, dict):
        for k, v in lc.items():
            if isinstance(v, dict) and "titleSlug" in v and "content" in v:
                slug_to_desc[v["titleSlug"]] = v["content"]
    elif isinstance(lc, list):
        for item in lc:
            if "stat" in item:  # typical raw leetcode format
                slug = item["stat"].get("question__title_slug")
                # wait, old API didn't have content in this list. 
                pass

    print(f"Found {len(slug_to_desc)} descriptions in leetcode-all-problems.json (if 0, we need another way).")

if __name__ == "__main__":
    main()
