#!/usr/bin/env python3
import os
import re

def get_solution_code(filepath):
    if not os.path.exists(filepath):
        return None
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()
    
    start_match = re.search(r'// @lc code=start', content)
    end_match = re.search(r'// @lc code=end', content)
    
    if start_match and end_match:
        return content[start_match.end():end_match.start()].strip()
    return None

def update_overview():
    overview_path = "overview.md"
    if not os.path.exists(overview_path):
        print(f"Error: {overview_path} not found in the current directory.")
        return

    with open(overview_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    new_lines = []
    skip_mode = False
    
    for line in lines:
        # Check if we are starting a previously injected details block
        if line.strip() == "<details><summary>View Solution</summary>":
            skip_mode = True
        
        if skip_mode:
            # Check if we reached the end of the previously injected details block
            if line.strip() == "</details>":
                skip_mode = False
            continue

        # If not skipping, keep the original line
        new_lines.append(line)
        
        # Check if this line represents a solved problem
        match = re.search(r'^- \[x\] \*\*\[LC \d+\]\(([^)]+)\)\*\*', line.strip())
        if match:
            filepath = match.group(1)
            code = get_solution_code(filepath)
            
            # If we found the solution code, inject the new details block
            if code:
                new_lines.append("  <details><summary>View Solution</summary>\n")
                new_lines.append("  \n")
                new_lines.append("  ```cpp\n")
                for code_line in code.split('\n'):
                    if code_line:
                        new_lines.append(f"  {code_line}\n")
                    else:
                        new_lines.append("  \n")
                new_lines.append("  ```\n")
                new_lines.append("  </details>\n")

    with open(overview_path, 'w', encoding='utf-8') as f:
        f.writelines(new_lines)
    print("overview.md updated successfully with collapsible solutions!")

if __name__ == "__main__":
    update_overview()
