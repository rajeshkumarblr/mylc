import json
import os
import glob
import re
import textwrap

REPO_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CPP_DIR = os.path.join(REPO_ROOT, "src", "cpp")

def main():
    with open(os.path.join(REPO_ROOT, "scripts", "neetcode_descriptions.json"), "r") as f:
        descriptions = json.load(f)
        
    cpp_files = glob.glob(os.path.join(CPP_DIR, "*", "*.cpp"))
    
    count = 0
    for file_path in cpp_files:
        filename = os.path.basename(file_path)
        # filename is typically <id>.<slug>.cpp
        match = re.match(r"^(\d+)\.", filename)
        if not match:
            continue
        pid = match.group(1)
        
        if pid not in descriptions:
            continue
            
        desc = descriptions[pid]
        # format desc for comment block
        wrapped_desc = "\n".join(" * " + line for p in desc.split("\n") for line in textwrap.wrap(p, width=75))
        
        with open(file_path, "r") as f:
            content = f.read()
            
        if "Description:" in content:
            continue # already injected
            
        # find the end of the top comment block
        header_end_idx = content.find(" */")
        if header_end_idx == -1:
            continue
            
        # insert description before " */"
        new_content = content[:header_end_idx] + " *\n * Description:\n" + wrapped_desc + "\n" + content[header_end_idx:]
        
        with open(file_path, "w") as f:
            f.write(new_content)
        count += 1
        
    print(f"Injected descriptions into {count} files.")

if __name__ == "__main__":
    main()
