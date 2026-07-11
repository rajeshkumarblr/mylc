import json
import os
import subprocess
import glob

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

def main():
    with open(os.path.join(REPO_ROOT, "scripts", "neetcode_flat.json"), "r") as f:
        problems = json.load(f)
        
    solved_ids = set()
    
    # We can parse the output of `./run -a` to get the status for all problems much faster.
    print("Running all tests to determine solved status...")
    try:
        # Timeout 30 seconds for the entire run -a. If it hangs, we might need to do it individually.
        res = subprocess.run(["./run", "-a"], cwd=REPO_ROOT, capture_output=True, text=True, timeout=30)
        output = res.stdout
    except subprocess.TimeoutExpired as e:
        print("Tests timed out! Output so far:")
        output = e.stdout
        
    # Example output per problem:
    # Mode: single problem 1
    # No   Description                 Category        Result Cases
    # 1    Two Sum                     hash            Pass   [1 2]
    # Summary: problems=1, passed=1, failed=0, total_cases=2
    # Final Result: PASS yes
    
    # We can grep for "Final Result: PASS yes" but `./run -a` groups everything.
    # Ah, `./run -a` output:
    # No   Description                 Category        Result Cases
    # 1    Two Sum                     hash            Pass   [1 2]
    # ...
    # Let's parse the lines that look like:
    # 1    Two Sum                     hash            Pass   [1 2]
    
    for line in output.split('\n'):
        parts = line.split()
        if not parts: continue
        
        # Check if first token is a number
        if parts[0].isdigit():
            pid = parts[0]
            if "Pass" in parts or "PASS" in parts:
                # Need to be careful, what if the description contains "Pass"?
                # Result is usually the 2nd to last or 3rd to last column.
                # Actually, the format is: ID Description Category Result Cases
                if "Pass" in line or "Fail" in line:
                    if "Pass" in line.split()[-2:]:
                        solved_ids.add(pid)
                    elif "Pass" in line.split()[-3:]:
                        solved_ids.add(pid)
    
    print(f"Found {len(solved_ids)} completely passing problems.")
    
    # Write to a cache so generate_overview.py can use it
    with open(os.path.join(REPO_ROOT, "scripts", "solved_status.json"), "w") as f:
        json.dump(list(solved_ids), f)
        
if __name__ == "__main__":
    main()
