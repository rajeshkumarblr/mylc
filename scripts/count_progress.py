import re

with open("overview.md", "r", encoding="utf-8") as f:
    lines = f.readlines()

current_category = None
solved_count = 0
total_count = 0
stats = []

for line in lines:
    if line.startswith("## ") and not line.startswith("## 📚"):
        if current_category:
            stats.append((current_category, solved_count, total_count))
        current_category = line.strip()[3:]
        solved_count = 0
        total_count = 0
    elif line.startswith("- [x]"):
        if current_category:
            solved_count += 1
            total_count += 1
    elif line.startswith("- [ ]"):
        if current_category:
            total_count += 1

if current_category:
    stats.append((current_category, solved_count, total_count))

print("## 📊 Progress Summary\n")
print("| Category | Solved | Total | Progress |")
print("|----------|--------|-------|----------|")
total_s = 0
total_t = 0
for cat, s, t in stats:
    if t == 0: continue
    total_s += s
    total_t += t
    # progress bar
    filled = int((s/t) * 10)
    bar = "🟩" * filled + "⬜" * (10 - filled)
    percent = int(s/t*100)
    print(f"| {cat} | {s} | {t} | {bar} {percent}% |")

if total_t > 0:
    filled = int((total_s/total_t) * 10)
    bar = "🟩" * filled + "⬜" * (10 - filled)
    percent_total = int(total_s/total_t*100)
    print(f"| **Total** | **{total_s}** | **{total_t}** | **{bar} {percent_total}%** |\n")
