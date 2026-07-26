import re
import json
import os
import urllib.request

def generate_data():
    if not os.path.exists("overview.md"):
        print("overview.md not found!")
        return

    with open("overview.md", "r") as f:
        lines = f.readlines()

    # Load neetcode_descriptions.json if it exists
    desc_cache = {}
    if os.path.exists("scripts/neetcode_descriptions.json"):
        try:
            with open("scripts/neetcode_descriptions.json", "r") as f:
                desc_cache = json.load(f)
        except Exception:
            pass

    # Load local gql cache
    gql_cache = {}
    cache_file = "scripts/leetcode_cache.json"
    if os.path.exists(cache_file):
        try:
            with open(cache_file, "r") as f:
                gql_cache = json.load(f)
        except Exception:
            pass

    data = {
        "categories": [],
        "problems": {}
    }

    current_category = None
    
    # Regex to capture problem line
    # Format: - [x] **[LC 70](src/cpp/dp/70.climbing-stairs.cpp)**: [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) 🟢
    prob_pattern = re.compile(r'- \[([x ])\] \*\*\[LC (\d+)\]\((.*?)\)\*\*: \[(.*?)\]\((.*?)\) (.*)')
    video_pattern = re.compile(r'\[🎬 Video explanation\]\((.*?)\)')

    current_problem_id = None

    for line in lines:
        line = line.strip()
        
        if line.startswith("## ") and not line.startswith("## User Review Required") and not line.startswith("## 📚 STL Quick References"):
            cat_name = line[3:].strip()
            if cat_name in ["Proposed Changes", "Verification Plan", "Open Questions", "User Review Required", "📊 Progress Summary"]:
                continue
                
            # Rename dynamic programming categories
            if cat_name == "1-D Dynamic Programming":
                cat_name = "Dynamic Programming (1D)"
            elif cat_name == "2-D Dynamic Programming":
                cat_name = "Dynamic Programming (2D)"
                
            current_category = cat_name
            data["categories"].append({
                "name": cat_name,
                "problems": []
            })
            continue

        prob_match = prob_pattern.search(line)
        if prob_match and current_category:
            is_solved = prob_match.group(1) == 'x'
            prob_id = prob_match.group(2)
            local_path = prob_match.group(3)
            title = prob_match.group(4)
            lc_url = prob_match.group(5)
            status_icon = prob_match.group(6) # e.g. 🟢, 🟡, 🔴

            current_problem_id = prob_id
            code_content = ""
            desc = ""
            difficulty = "Medium"
            if os.path.exists(local_path):
                with open(local_path, "r") as cf:
                    code_content = cf.read()
                    
                # Extract Difficulty
                diff_match = re.search(r'\*\s+Difficulty:\s*(.*)', code_content)
                if diff_match:
                    difficulty = diff_match.group(1).strip()

                # Extract Description from C++ block comment
                desc_match = re.search(r'\*\s+Description:\s*(.*?)\*/', code_content, re.DOTALL)
                if desc_match:
                    desc_raw = desc_match.group(1)
                    # Remove the ' * ' prefix on each line
                    desc = "\n".join([l.strip().lstrip('*').strip() for l in desc_raw.split('\n') if l.strip()])

                # Extract Code only
                code_match = re.search(r'// @lc code=start(.*?)// @lc code=end', code_content, re.DOTALL)
                if code_match:
                    code_content = code_match.group(1).strip()
                else:
                    # Fallback
                    code_content = re.sub(r'#include.*?\n', '', code_content)
                    code_content = re.sub(r'using namespace std;\n', '', code_content)
                    code_content = re.sub(r'int main\(\)\s*\{.*?$', '', code_content, flags=re.DOTALL)
                    code_content = code_content.strip()

            approach_content = None
            approach_file = f"docs/approaches/{prob_id}.md"
            if os.path.exists(approach_file):
                with open(approach_file, "r") as af:
                    approach_content = af.read()

            title_slug = lc_url.rstrip('/').split('/')[-1]
            desc_html = gql_cache.get(title_slug)

            # Fetch via GraphQL if not cached and has internet access
            if not desc_html:
                url_gql = "https://leetcode.com/graphql"
                query_gql = """
                query questionData($titleSlug: String!) {
                  question(titleSlug: $titleSlug) {
                    content
                  }
                }
                """
                try:
                    req_data = json.dumps({"query": query_gql, "variables": {"titleSlug": title_slug}}).encode('utf-8')
                    req = urllib.request.Request(
                        url_gql, 
                        data=req_data, 
                        headers={
                            'Content-Type': 'application/json',
                            'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
                        }
                    )
                    with urllib.request.urlopen(req, timeout=5) as response:
                        if response.status == 200:
                            resp_data = json.loads(response.read().decode('utf-8'))
                            if "data" in resp_data and resp_data["data"]["question"]:
                                desc_html = resp_data["data"]["question"]["content"]
                                if desc_html:
                                    gql_cache[title_slug] = desc_html
                except Exception as e:
                    print(f"Warning: Failed to fetch HTML for {title_slug}: {e}")

            # Fallback to local neetcode_descriptions if not in gql cache/fetched
            if not desc_html and prob_id in desc_cache:
                desc_html = desc_cache[prob_id]

            prob_data = {
                "id": prob_id,
                "title": title,
                "category": current_category,
                "status_icon": status_icon,
                "is_solved": is_solved,
                "difficulty": difficulty,
                "local_path": local_path,
                "lc_url": lc_url,
                "video_url": None,
                "code": code_content,
                "description": desc,
                "description_html": desc_html,
                "approach": approach_content
            }
            
            data["problems"][prob_id] = prob_data
            data["categories"][-1]["problems"].append(prob_id)
            continue
            
        video_match = video_pattern.search(line)
        if video_match and current_problem_id:
            vid_url = video_match.group(1)
            # Convert watch?v=XYZ to embed/XYZ
            if "watch?v=" in vid_url:
                vid_url = vid_url.replace("watch?v=", "embed/")
            data["problems"][current_problem_id]["video_url"] = vid_url
            current_problem_id = None

    # Save the updated gql cache
    try:
        with open(cache_file, "w") as out:
            json.dump(gql_cache, out, indent=2)
    except Exception as e:
        print(f"Warning: Failed to save leetcode_cache.json: {e}")

    os.makedirs("dashboard/public", exist_ok=True)
    with open("dashboard/public/data.json", "w") as out:
        json.dump(data, out, indent=2)
    
    print("Dashboard data generated at dashboard/public/data.json!")

if __name__ == "__main__":
    generate_data()
