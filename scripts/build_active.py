#!/usr/bin/env python3
import os
import sys
import subprocess
import pathlib

def main():
    if len(sys.argv) < 2:
        print("Usage: build_active.py [--id <problem_id> | <active_file_path>]", file=sys.stderr)
        sys.exit(1)
        
    repo_root = pathlib.Path(__file__).resolve().parent.parent
    src_cpp = repo_root / "src" / "cpp"
    
    category = None
    basename = None
    
    if sys.argv[1] == "--id":
        if len(sys.argv) < 3:
            print("Error: --id requires a problem ID", file=sys.stderr)
            sys.exit(1)
        prob_id = sys.argv[2]
        # Find the source file for this problem ID
        found_file = None
        # category directories
        categories = ["backtracking", "binary_search", "bit_manipulation", "concurrency", "dp", "graphs", "greedy", "hash", "heap", "intervals", "list", "math", "misc", "prefix_sum", "sliding_window", "stack", "tree", "trie", "two_pointer"]
        for cat in categories:
            cat_dir = src_cpp / cat
            if cat_dir.exists():
                for f in cat_dir.glob(f"{prob_id}.*.cpp"):
                    found_file = f
                    break
            if found_file:
                break
        
        if not found_file:
            print(f"Error: C++ solution for problem ID '{prob_id}' not found under src/cpp/", file=sys.stderr)
            sys.exit(1)
            
        rel_path = found_file.relative_to(src_cpp)
        category = rel_path.parts[0]
        filename = rel_path.parts[1]
        basename = filename[:-4]
    else:
        active_file = pathlib.Path(sys.argv[1]).resolve()
        # Check if the active file is inside src/cpp
        try:
            rel_path = active_file.relative_to(src_cpp)
        except ValueError:
            print(f"Error: Active file {active_file} is not under {src_cpp}", file=sys.stderr)
            sys.exit(1)
            
        parts = rel_path.parts
        if len(parts) < 2:
            print(f"Error: Active file {active_file} must be in a category subdirectory under {src_cpp}", file=sys.stderr)
            sys.exit(1)
            
        category = parts[0]
        filename = parts[1]
        if not filename.endswith(".cpp"):
            print(f"Error: Active file {active_file} is not a C++ file", file=sys.stderr)
            sys.exit(1)
            
        basename = filename[:-4]
        
    p_val = f"{category}/{basename}"
    
    # Run make to build dbg-one
    cmd = ["make", "-C", str(src_cpp), "dbg-one", f"P={p_val}"]
    print(f"Running: {' '.join(cmd)}")
    res = subprocess.run(cmd)
    if res.returncode != 0:
        sys.exit(res.returncode)
        
    # Symlink or copy the compiled dbg binary to a fixed location: build/cpp/debug_target
    dbg_bin = repo_root / "build" / "cpp" / "dbg" / category / basename
    target_link = repo_root / "build" / "cpp" / "debug_target"
    
    # Create build/cpp directory if not exists
    target_link.parent.mkdir(parents=True, exist_ok=True)
    
    if target_link.exists() or target_link.is_symlink():
        target_link.unlink()
        
    os.symlink(os.path.relpath(dbg_bin, target_link.parent), target_link)
    print(f"Created symlink: {target_link} -> {dbg_bin}")

if __name__ == "__main__":
    main()
