import os
import json

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OVERVIEW_PATH = os.path.join(REPO_ROOT, "overview.md")

def main():
    with open(os.path.join(REPO_ROOT, "scripts", "neetcode_flat.json"), "r") as f:
        problems = json.load(f)
        
    with open(os.path.join(REPO_ROOT, "testcases.json"), "r") as f:
        testcases = json.load(f)

    # Group by NeetCode category
    grouped = {}
    for p in problems:
        cat = p["category"]
        if cat not in grouped:
            grouped[cat] = []
        grouped[cat].append(p)
        
    content = "# NeetCode 150 Overview\n\n"
    content += "Track your interview preparation progress here.\n\n"
    
    for cat in sorted(grouped.keys()):
        content += f"## {cat}\n\n"
        for p in grouped[cat]:
            pid = str(p["id"])
            slug = p["slug"]
            name = p["name"]
            diff = p["difficulty"]
            url = p.get("url", f"https://leetcode.com/problems/{slug}/")
            
            repo_cat = testcases.get(pid, {}).get("category", "misc")
            local_path = f"src/cpp/{repo_cat}/{pid}.{slug}.cpp"
            
            # Check if solved
            is_solved = (p.get("existing_path") is not None)
                        
            checkbox = "[x]" if is_solved else "[ ]"
            diff_emoji = "🟢" if diff == "Easy" else ("🟡" if diff == "Medium" else "🔴")
            
            content += f"- {checkbox} **[LC {pid}]({local_path})**: [{name}]({url}) {diff_emoji}\n"
        content += "\n"
        
    with open(OVERVIEW_PATH, "w", encoding="utf-8") as f:
        f.write(content)
        
    print(f"Generated overview.md with {len(problems)} problems.")

if __name__ == "__main__":
    main()
