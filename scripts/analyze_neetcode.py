import os
import json
import re

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NEETCODE_LIST_PATH = os.path.join(REPO_ROOT, "scripts", "neetcode-150-list.json")
LEETCODE_ALL_PATH = os.path.join(REPO_ROOT, "scripts", "leetcode-all-problems.json")
CPP_SRC_DIR = os.path.join(REPO_ROOT, "src", "cpp")

def main():
    # Load Neetcode 150 list
    with open(NEETCODE_LIST_PATH, "r") as f:
        neetcode_data = json.load(f)
    
    # Load all Leetcode problems to map slug -> ID
    with open(LEETCODE_ALL_PATH, "r") as f:
        leetcode_data = json.load(f)
    
    slug_to_id = {}
    for pair in leetcode_data.get("stat_status_pairs", []):
        stat = pair.get("stat", {})
        slug = stat.get("question__title_slug")
        fid = stat.get("frontend_question_id")
        if slug and fid:
            slug_to_id[slug] = int(fid)
            
    # Normalize NeetCode list into a flat list of problems with ID, slug, category, difficulty
    nc_problems = []
    for cat_name, probs in neetcode_data.items():
        for prob_name, details in probs.items():
            url = details.get("url", "")
            # Extract slug from url: https://leetcode.com/problems/contains-duplicate/ -> contains-duplicate
            match = re.search(r"/problems/([^/]+)/?", url)
            if match:
                slug = match.group(1)
            else:
                slug = prob_name.lower().replace(" ", "-") # fallback
            
            fid = slug_to_id.get(slug)
            # Some manual fixes for known different slugs
            if not fid:
                # Let's try matching case insensitively or with minor adjustments
                normalized_slug = slug.replace("-", "")
                for s, i in slug_to_id.items():
                    if s.replace("-", "") == normalized_slug:
                        fid = i
                        slug = s
                        break
            
            nc_problems.append({
                "name": prob_name,
                "slug": slug,
                "id": fid,
                "category": cat_name,
                "difficulty": details.get("difficulty"),
                "url": url
            })
            
    # Find existing C++ files in the workspace
    # Format of C++ files is usually <id>.<slug>.cpp
    existing_cpp_files = {}
    for root, dirs, files in os.walk(CPP_SRC_DIR):
        for file in files:
            if file.endswith(".cpp"):
                match = re.match(r"^(\d+)\.([^.]+)\.cpp$", file)
                if match:
                    fid = int(match.group(1))
                    existing_cpp_files[fid] = os.path.relpath(os.path.join(root, file), REPO_ROOT)
                    
    # Print summary
    matched = 0
    missing_id = 0
    results = []
    for p in nc_problems:
        fid = p["id"]
        if not fid:
            missing_id += 1
            print(f"ERROR: Could not find ID for {p['name']} (slug: {p['slug']})")
            continue
        
        existing_path = existing_cpp_files.get(fid)
        results.append({
            "id": fid,
            "name": p["name"],
            "slug": p["slug"],
            "category": p["category"],
            "difficulty": p["difficulty"],
            "existing_path": existing_path
        })
        if existing_path:
            matched += 1
            
    print(f"Total Neetcode 150 problems found: {len(nc_problems)}")
    print(f"Matched with IDs: {len(nc_problems) - missing_id}")
    print(f"Already solved/implemented in C++: {matched}")
    
    # Save the matched list
    with open(os.path.join(REPO_ROOT, "scripts", "neetcode_flat.json"), "w") as f:
        json.dump(results, f, indent=2)

if __name__ == "__main__":
    main()
