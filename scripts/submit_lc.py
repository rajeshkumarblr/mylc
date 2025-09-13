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
    patt = str((src_root / lang) / f"{problem_id}.*.{ext}")
    return sorted(Path(p) for p in glob.glob(patt))

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
    if not with_markers:
        raise RuntimeError("No file with @lc markers among: " + ", ".join(str(p) for p in cands))
    return with_markers[0]

def extract_block(src: Path) -> str:
    txt = src.read_text(encoding="utf-8", errors="ignore")
    m = re.search(r"@lc\s+code=start(.*)@lc\s+code=end", txt, flags=re.S)
    if not m:
        raise ValueError(f"Could not find @lc markers in {src}")
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
