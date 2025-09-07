#!/usr/bin/env python3
import json, argparse
p = argparse.ArgumentParser()
p.add_argument("--file", default="tags.json")
p.add_argument("--lang", default="cpp")
p.add_argument("--tag", required=True)
a = p.parse_args()
data = json.load(open(a.file))
ids = [e["id"] for e in data if a.lang in e.get("langs", []) and a.tag in e.get("tags", [])]
print(" ".join(sorted(ids)))
