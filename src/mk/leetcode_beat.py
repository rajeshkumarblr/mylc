#!/usr/bin/env python3
# stdlib-only LeetCode beat ratio helper using only recentSubmissions + submissionDetails

import argparse, json, ssl, sys
from pathlib import Path
from urllib.request import Request, urlopen
from urllib.error import HTTPError, URLError

HOST = "https://leetcode.com"

CAND_COOKIE_PATHS = [
    Path("~/.leetcode/user.json").expanduser(),
    Path("~/.lc/leetcode/user.json").expanduser(),
]

def _parse_cookie_string(cookie_str: str):
    kv = {}
    for part in (cookie_str or "").split(";"):
        part = part.strip()
        if not part or "=" not in part: continue
        k, v = part.split("=", 1)
        kv[k.strip()] = v.strip()
    return kv

def load_cookie_bundle():
    """
    Return {"cookie_header": "...", "x_csrf": "..."} by reading user.json from
    ~/.leetcode or ~/.lc/leetcode, supporting both "cookie" (string) and separate keys.
    """
    for p in CAND_COOKIE_PATHS:
        if not p.exists(): continue
        try:
            data = json.loads(p.read_text())
        except Exception:
            continue

        cookie_header = None
        if isinstance(data.get("cookie"), str) and "LEETCODE_SESSION=" in data["cookie"]:
            cookie_header = data["cookie"]
        elif isinstance(data.get("cookies"), str) and "LEETCODE_SESSION=" in data["cookies"]:
            cookie_header = data["cookies"]

        parsed = _parse_cookie_string(cookie_header) if cookie_header else {}

        if "LEETCODE_SESSION" not in parsed:
            ses = data.get("LEETCODE_SESSION") or data.get("session") or (data.get("cookies") or {}).get("LEETCODE_SESSION")
            if ses: parsed["LEETCODE_SESSION"] = ses
        if "csrftoken" not in parsed:
            csrf = data.get("csrftoken") or data.get("csrf") or (data.get("cookies") or {}).get("csrftoken")
            if csrf: parsed["csrftoken"] = csrf

        x_csrf = data.get("sessionCSRF") or parsed.get("csrftoken")

        if not cookie_header:
            bits = []
            if parsed.get("LEETCODE_SESSION"): bits.append(f"LEETCODE_SESSION={parsed['LEETCODE_SESSION']}")
            if parsed.get("csrftoken"):        bits.append(f"csrftoken={parsed['csrftoken']}")
            cookie_header = "; ".join(bits)

        if cookie_header and x_csrf:
            return {"cookie_header": cookie_header, "x_csrf": x_csrf}
    return None

def graphql(query: str, variables: dict, cookie_bundle: dict, referer: str):
    body = json.dumps({"query": query, "variables": variables}).encode("utf-8")
    headers = {
        "Accept": "application/json,text/plain,*/*",
        "Content-Type": "application/json",
        "Origin": HOST,
        "Referer": referer,
        "x-csrftoken": cookie_bundle["x_csrf"],
        "Cookie": cookie_bundle["cookie_header"],
        "User-Agent": "leetcode-beat-stdlib/2.0",
        "X-Requested-With": "XMLHttpRequest",
    }
    req = Request(f"{HOST}/graphql/", data=body, headers=headers, method="POST")
    ctx = ssl.create_default_context()
    with urlopen(req, context=ctx, timeout=20) as resp:
        return json.loads(resp.read().decode("utf-8"))

def pick_latest_submission_id_for(pid: str, cookies: dict):
    # 1) Pull a page of recent submissions; filter by frontend id
    q = """
    query recentSubmissions($limit:Int!,$offset:Int!){
      recentSubmissions(limit:$limit, offset:$offset){
        url
        question{ questionFrontendId titleSlug }
      }
    }"""
    data = graphql(q, {"limit": 40, "offset": 0}, cookies, f"{HOST}/submissions/")
    items = (data.get("data") or {}).get("recentSubmissions") or []
    for it in items:
        qinfo = it.get("question") or {}
        if str(qinfo.get("questionFrontendId")) == str(pid):
            url = (it.get("url") or "")
            # e.g. /submissions/detail/123456789/
            import re
            m = re.search(r"/submissions/detail/(\d+)/", url)
            if m: return int(m.group(1)), qinfo.get("titleSlug")
    return None, None

def fetch_submission_details(sid: int, slug: str | None, cookies: dict):
    q = """
    query submissionDetails($submissionId:Int!){
      submissionDetails(submissionId:$submissionId){
        runtime runtimeDisplay
        memory memoryDisplay
        runtimePercentile memoryPercentile
        lang statusDisplay
      }
    }"""
    # Referer tied to this submission (or the problem submissions tab if slug is known)
    referer = f"{HOST}/submissions/detail/{sid}/"
    if slug:
        referer = f"{HOST}/problems/{slug}/submissions/"
    data = graphql(q, {"submissionId": sid}, cookies, referer)
    return (data.get("data") or {}).get("submissionDetails") or {}

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--id", required=True, help="LeetCode frontend problem id, e.g. 104")
    args = ap.parse_args()

    cookies = load_cookie_bundle()
    if not cookies:
        print("ERROR: LeetCode cookies not found (~/.leetcode/user.json or ~/.lc/leetcode/user.json).", file=sys.stderr)
        sys.exit(2)

    sid, slug = pick_latest_submission_id_for(args.id, cookies)
    if not sid:
        print("ERROR: Could not find a recent submission for this problem id. Submit once, then retry.", file=sys.stderr)
        sys.exit(3)

    det = fetch_submission_details(sid, slug, cookies)
    rp = det.get("runtimePercentile")
    mp = det.get("memoryPercentile")
    rt = det.get("runtimeDisplay") or det.get("runtime")
    mem = det.get("memoryDisplay") or det.get("memory")

    def pct(x):
        if isinstance(x, (int, float)): return f"{x:.1f}%"
        return x if x else "?"

    if rp is not None or mp is not None:
        print(f"→ Beat ratio: runtime {pct(rp)}{f' (time {rt})' if rt else ''}  |  memory {pct(mp)}{f' (mem {mem})' if mem else ''}")
    else:
        print("⚠ Beat ratio not returned by API for this submission.")

if __name__ == "__main__":
    try:
        main()
    except HTTPError as e:
        try:
            body = e.read().decode("utf-8", "ignore")
        except Exception:
            body = ""
        print(f"ERROR: HTTP {e.code}: {e} | body: {body[:400]}", file=sys.stderr)
        sys.exit(4)
    except URLError as e:
        print(f"ERROR: Network error: {e}", file=sys.stderr)
        sys.exit(5)
    except Exception as e:
        print(f"ERROR: {e}", file=sys.stderr)
        sys.exit(1)
