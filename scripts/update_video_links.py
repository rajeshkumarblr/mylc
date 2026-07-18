#!/usr/bin/env python3
import json
import re
import urllib.request
import urllib.parse
import time

def fetch_youtube_id(query):
    url = "https://www.youtube.com/results?search_query=" + urllib.parse.quote_plus(query)
    req = urllib.request.Request(url, headers={"User-Agent": "Mozilla/5.0"})
    try:
        html = urllib.request.urlopen(req).read().decode("utf-8")
        match = re.search(r'"videoId":"([^"]+)"', html)
        if match:
            return match.group(1)
    except Exception as e:
        print(f"Error fetching {query}: {e}")
    return None

def main():
    # 1. Parse overview.md to find all problems
    with open('overview.md', 'r', encoding='utf-8') as f:
        overview_content = f.read()

    pattern = r'\*\*\[LC (\d+)\]\([^)]+\)\*\*: \[([^\]]+)\]'
    problems = re.findall(pattern, overview_content)
    
    # 2. Update neetcode_links.json
    try:
        with open('scripts/neetcode_links.json', 'r', encoding='utf-8') as f:
            links = json.load(f)
    except FileNotFoundError:
        links = {}
        
    print(f"Found {len(problems)} problems in overview.md")
    updated = False
    
    for prob_num, prob_title in problems:
        current_link = links.get(prob_num, "")
        
        # If link is missing or is just a search query link, we fetch the real ID
        if not current_link or "search_query" in current_link:
            print(f"Fetching real video ID for LC {prob_num} - {prob_title}...")
            query = f"neetcode {prob_num} {prob_title.lower()}"
            video_id = fetch_youtube_id(query)
            if video_id:
                links[prob_num] = f"https://www.youtube.com/watch?v={video_id}"
                updated = True
                print(f"  -> Found: {links[prob_num]}")
                time.sleep(0.5) # Be gentle to YouTube
            else:
                print("  -> Not found!")
                
    if updated:
        with open('scripts/neetcode_links.json', 'w', encoding='utf-8') as f:
            json.dump(links, f, indent=2)
        print(f"Saved updated links to neetcode_links.json.")
    
    # 3. Update overview.md with the links
    new_overview_content = overview_content
    for prob_num, prob_title in problems:
        url = links.get(prob_num)
        if not url: continue
        
        # Look for the exact line containing this problem
        # (- [x] **[LC 746](...)**: [Min Cost Climbing Stairs](...) 🟢)
        line_pattern = rf'(- \[[x ]\] \*\*\[LC {prob_num}\][^\n]+(?:🟢|🟡|🔴))'
        
        def replacer(match):
            original_line = match.group(1)
            # Add the video link on the NEXT line, indented by 2 spaces
            # But ensure we don't duplicate it if it's already there (though we reverted overview.md so it shouldn't be)
            return f"{original_line}\n  [🎬 Video]({url})"
            
        new_overview_content = re.sub(line_pattern, replacer, new_overview_content)
        
    with open('overview.md', 'w', encoding='utf-8') as f:
        f.write(new_overview_content)
        
    print("Successfully appended video links to overview.md!")

if __name__ == "__main__":
    main()
