import urllib.request
import json
import time
import os
import re

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def strip_html(html_str):
    # basic html stripping
    text = re.sub(r'<[^>]+>', ' ', html_str)
    # unescape common html entities
    text = text.replace("&nbsp;", " ")
    text = text.replace("&lt;", "<")
    text = text.replace("&gt;", ">")
    text = text.replace("&amp;", "&")
    text = text.replace("&quot;", "\"")
    text = text.replace("&#39;", "'")
    # clean up extra spaces
    text = re.sub(r'\n\s*\n', '\n\n', text)
    return text.strip()

def main():
    with open(os.path.join(REPO_ROOT, "scripts", "neetcode_flat.json"), "r") as f:
        problems = json.load(f)
        
    out_path = os.path.join(REPO_ROOT, "scripts", "neetcode_descriptions.json")
    descriptions = {}
    if os.path.exists(out_path):
        with open(out_path, "r") as f:
            descriptions = json.load(f)
            
    url = "https://leetcode.com/graphql"
    query = """
    query questionContent($titleSlug: String!) {
      question(titleSlug: $titleSlug) {
        content
      }
    }
    """
    
    headers = {
        "Content-Type": "application/json",
        "User-Agent": "Mozilla/5.0"
    }

    count = 0
    for p in problems:
        pid = str(p["id"])
        slug = p["slug"]
        
        if pid in descriptions:
            continue
            
        data = {
            "query": query,
            "variables": {"titleSlug": slug}
        }
        
        req = urllib.request.Request(url, data=json.dumps(data).encode("utf-8"), headers=headers)
        try:
            with urllib.request.urlopen(req) as resp:
                resp_data = json.loads(resp.read().decode("utf-8"))
                content = resp_data.get("data", {}).get("question", {}).get("content", "")
                if content:
                    descriptions[pid] = strip_html(content)
                else:
                    descriptions[pid] = "Premium problem or no description found."
            count += 1
            time.sleep(0.5) # rate limit
        except Exception as e:
            print(f"Failed to fetch {slug}: {e}")
            descriptions[pid] = "Failed to fetch description."

    with open(out_path, "w") as f:
        json.dump(descriptions, f, indent=2)
        
    print(f"Fetched {count} new descriptions.")

if __name__ == "__main__":
    main()
