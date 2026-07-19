import os
import re

with open("overview.md", "r", encoding="utf-8") as f:
    content = f.read()

# 1. Extract and remove STL section
stl_start_marker = "## 📚 STL Quick References"
start_idx = content.find(stl_start_marker)
if start_idx != -1:
    end_marker = "---"
    end_idx = content.find(end_marker, start_idx)
    
    if end_idx != -1:
        end_idx += len(end_marker)
        stl_section = content[start_idx:end_idx]
        
        # Remove from original
        content = content[:start_idx] + content[end_idx:]
        
        # Process STL section
        stl_lines = stl_section.strip().split('\n')
        new_stl_lines = []
        
        file_mapping = {
            "1": "01_vector.cpp",
            "2": "02_list.cpp",
            "3": "03_deque.cpp",
            "4": "04_queue.cpp",
            "5": "05_stack.cpp",
            "6": "06_set.cpp",
            "7": "07_map.cpp",
            "8": "08_unordered_set.cpp",
            "9": "09_unordered_map.cpp",
            "10": "10_priority_queue.cpp",
        }
        
        for line in stl_lines:
            new_stl_lines.append(line)
            match = re.search(r'`./run -e (\d+)`', line)
            if match:
                num = match.group(1)
                if num in file_mapping:
                    filepath = os.path.join("src", "cpp", "stl", file_mapping[num])
                    if os.path.exists(filepath):
                        with open(filepath, "r", encoding="utf-8") as code_file:
                            code = code_file.read().strip()
                        new_stl_lines.append("  <details><summary>View Example</summary>\n  \n  ```cpp\n" + "\n".join("  " + l for l in code.split("\n")) + "\n  ```\n  </details>")
        
        final_stl_section = "\n".join(new_stl_lines)
        
        # Append to the very end of the file
        content = content.strip() + "\n\n---\n\n" + final_stl_section + "\n"

# 2. Fix the markdown line breaking for "Video explanation"
def fix_newlines(m):
    prev_line = m.group(1).rstrip()
    return f"{prev_line}  \n{m.group(2)}[🎬 Video explanation]"

content = re.sub(r'^(.*?)\n(\s+)\[🎬 Video explanation\]', fix_newlines, content, flags=re.MULTILINE)

with open("overview.md", "w", encoding="utf-8") as f:
    f.write(content)
