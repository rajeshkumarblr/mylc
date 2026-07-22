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

    data = {
        "categories": [],
        "problems": {}
    }

    current_category = None
    
    # Regex to capture problem line
    prob_pattern = re.compile(r'- <a id="lc-\d+"></a>(.) \[([x ])\] \*\*\[LC (\d+)\]\((.*?)\)\*\*: \[(.*?)\]\((.*?)\)')
    video_pattern = re.compile(r'\[🎬 Video explanation\]\((.*?)\)')

    current_problem_id = None

    for line in lines:
        line = line.strip()
        
        if line.startswith("## ") and not line.startswith("## User Review Required"):
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
            status_icon = prob_match.group(1) # e.g. 🟢, 🟡, ⬜
            is_solved = prob_match.group(2) == 'x'
            prob_id = prob_match.group(3)
            local_path = prob_match.group(4)
            title = prob_match.group(5)
            lc_url = prob_match.group(6)

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
            desc_html = None
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
            except Exception as e:
                print(f"Warning: Failed to fetch HTML for {title_slug}: {e}")

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

    os.makedirs("dashboard/public", exist_ok=True)
    with open("dashboard/public/data.json", "w") as out:
        json.dump(data, out, indent=2)
    
    print("Dashboard data generated at dashboard/public/data.json!")

if __name__ == "__main__":
    generate_data()
