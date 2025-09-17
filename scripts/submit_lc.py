#!/usr/bin/env python3
import argparse, glob, re, sys, subprocess
from pathlib import Path
from typing import List

# ---------- tiny shell helper (stream output) ----------
def run_stream(cmd: List[str]) -> int:
    proc = subprocess.Popen(cmd, stdout=sys.stdout, stderr=sys.stderr, text=True)
    return proc.wait()

# ---------- file discovery & extraction ----------
def candidate_sources(problem_id: str, lang: str, src_root: Path) -> List[Path]:
    ext = "cpp" if lang == "cpp" else "go"
    base = (src_root / lang)
    patterns = [
        str(base / f"{problem_id}.*.{ext}"),           # top-level
        str(base / "*" / f"{problem_id}.*.{ext}"),    # category subdirs
    ]
    files: List[Path] = []
    for patt in patterns:
        files.extend(Path(p) for p in glob.glob(patt))
    return sorted({p.resolve() for p in files})

def has_markers(p: Path) -> bool:
    try:
        t = p.read_text(encoding="utf-8", errors="ignore")
    except Exception:
        return False
    return "@lc code=start" in t and "@lc code=end" in t

def pick_source(problem_id: str, lang: str, src_root: Path, verbose=False) -> Path:
    cands = candidate_sources(problem_id, lang, src_root)
    if verbose:
        print(f"[submit] candidates: {[str(p) for p in cands]}")
    if not cands:
        raise FileNotFoundError(f"No source for id={problem_id} under {src_root/lang}")
    with_markers = [p for p in cands if has_markers(p)]
    # Prefer a file with markers; otherwise fall back to the first candidate
    return (with_markers[0] if with_markers else cands[0])

def extract_block(src: Path) -> str:
    txt = src.read_text(encoding="utf-8", errors="ignore")
    m = re.search(r"@lc\s+code=start(.*)@lc\s+code=end", txt, flags=re.S)
    if not m:
        # No markers: return full file content
        return txt
    snippet = (m.group(1) or "").strip()
    if len(snippet) < 16:
        raise ValueError(f"Extracted snippet from {src} is too small ({len(snippet)} chars).")
    return snippet + "\n"

def main():
    ap = argparse.ArgumentParser(description="Submit to LeetCode using vsc-leetcode-cli; stream output (no GraphQL).")
    ap.add_argument("--id", required=True, help="Problem ID (e.g., 1)")
    ap.add_argument("--lang", choices=["cpp","go"], default="cpp")
    ap.add_argument("--src-root", default="src", help="expects src/cpp or src/go")
    ap.add_argument("--build-root", default="build")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args()

    src_root   = Path(args.src_root).resolve()
    build_root = Path(args.build_root).resolve()
    ext = "cpp" if args.lang == "cpp" else "go"

    # 1) locate & extract @lc block
    src = pick_source(args.id, args.lang, src_root, args.verbose)
    if args.verbose:
        print(f"[submit] source: {src}")
    snippet = extract_block(src)
    # Make Go submissions self-contained if they rely on small utils
    if args.lang == "go":
        if "allZero(" in snippet and "func allZero(" not in snippet:
            helper = """
func allZero(cnt []int) bool {
    for _, v := range cnt {
        if v != 0 {
            return false
        }
    }
    return true
}
"""
            # Insert helper after package line if present, else prepend
            if snippet.strip().startswith("package "):
                lines = snippet.splitlines(True)
                # find first non-package line to insert after package declaration and any blank line
                insert_idx = 1
                if len(lines) >= 2 and lines[1].strip() == "":
                    insert_idx = 2
                lines[insert_idx:insert_idx] = [helper]
                snippet = "".join(lines)
            else:
                snippet = helper + snippet
    out_dir = build_root / args.lang / "submit"
    out_dir.mkdir(parents=True, exist_ok=True)
    snip_path = out_dir / f"{args.id}.{ext}"
    snip_path.write_text(snippet, encoding="utf-8")
    if args.verbose:
        print(f"[submit] wrote snippet -> {snip_path}")

    # 2) call the CLI and stream its own output (includes beat ratios)
    # Make sure your PATH points to vsc-leetcode-cli's `leetcode`
    #   npm uninstall -g leetcode-cli
    #   npm install -g vsc-leetcode-cli
    rc = run_stream(["leetcode", "submit", str(snip_path)])
    sys.exit(rc)

if __name__ == "__main__":
    main()
