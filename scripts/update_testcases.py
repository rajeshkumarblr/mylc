import json
import os

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
NEETCODE_FLAT_PATH = os.path.join(REPO_ROOT, "scripts", "neetcode_flat.json")
TESTCASES_PATH = os.path.join(REPO_ROOT, "testcases.json")

def main():
    # Load flat list
    with open(NEETCODE_FLAT_PATH, "r") as f:
        problems = json.load(f)
        
    # Load testcases.json
    with open(TESTCASES_PATH, "r") as f:
        testcases = json.load(f)
        
    added_count = 0
    updated_count = 0
    
    for p in problems:
        pid_str = str(p["id"])
        
        # Check if already exists in testcases.json
        if pid_str in testcases:
            # Optionally update category/difficulty if needed, but preserve existing
            updated_count += 1
        else:
            # Create a new skeleton entry
            testcases[pid_str] = {
                "category": "neet150", # Group them under neet150 category
                "description": p["name"],
                "difficulty": p["difficulty"].lower(),
                "url": p.get("url", f"https://leetcode.com/problems/{p['slug']}/"),
                "cases": []
            }
            added_count += 1
            
    # Write back to testcases.json
    with open(TESTCASES_PATH, "w", encoding="utf-8") as f:
        json.dump(testcases, f, indent=2)
        
    print(f"Updated testcases.json:")
    print(f"Added {added_count} new problem skeletons.")
    print(f"Preserved {updated_count} existing problems.")

if __name__ == "__main__":
    main()
