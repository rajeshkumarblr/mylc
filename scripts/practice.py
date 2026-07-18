#!/usr/bin/env python3
import os
import sys
import re
import subprocess
import argparse

def get_file_for_problem(prob_num):
    src_dir = "src/cpp"
        
    for root, dirs, files in os.walk(src_dir):
        for f in files:
            if f.startswith(f"{prob_num}.") and f.endswith(".cpp"):
                return os.path.join(root, f)
    return None

def get_original_stub(filepath):
    # Find the commit that added the file
    cmd = ["git", "log", "--diff-filter=A", "--format=%H", "-1", "--", filepath]
    result = subprocess.run(cmd, capture_output=True, text=True)
    commit = result.stdout.strip()
    
    if not commit:
        # Fallback to the oldest commit of the file
        cmd = ["git", "log", "--reverse", "--format=%H", "-1", "--", filepath]
        result = subprocess.run(cmd, capture_output=True, text=True)
        commit = result.stdout.strip()
        
    if not commit:
        print(f"Error: Could not find commit history for {filepath}")
        return None
        
    # Get the file contents from that commit
    cmd = ["git", "show", f"{commit}:{filepath}"]
    result = subprocess.run(cmd, capture_output=True, text=True)
    content = result.stdout
    
    start_match = re.search(r'// @lc code=start', content)
    end_match = re.search(r'// @lc code=end', content)
    
    if start_match and end_match:
        return content[start_match.start():end_match.end()]
        
    print(f"Error: Could not find // @lc code blocks in historical commit {commit}")
    return None

def strip_solution(prob_num):
    filepath = get_file_for_problem(prob_num)
    if not filepath:
        print(f"Error: Could not find C++ file for problem {prob_num}")
        return
        
    original_stub = get_original_stub(filepath)
    if not original_stub:
        print(f"Error: Could not extract original stub from git history for {filepath}")
        return
        
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
        
    # Replace the current block with the original block
    start_idx = content.find('// @lc code=start')
    end_idx = content.find('// @lc code=end')
    
    if start_idx == -1 or end_idx == -1:
        print(f"Error: Could not find // @lc code blocks in current file {filepath}")
        return
        
    new_content = content[:start_idx] + original_stub + content[end_idx + len('// @lc code=end'):]
    
    with open(filepath, 'w', encoding='utf-8') as f:
        f.write(new_content)
        
    print(f"Successfully stripped solution from {filepath}!")
    print(f"File has been reset to the original empty LeetCode stub. Ready for practice!")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Strip solution code for practice.")
    parser.add_argument("-p", "--problem", required=True, help="Problem number to strip")
    
    args = parser.parse_args()
    strip_solution(args.problem)
