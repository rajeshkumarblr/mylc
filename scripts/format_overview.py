import re

with open("overview.md", "r", encoding="utf-8") as f:
    content = f.read()

# 1. Fix the table
def slugify(text):
    text = text.lower()
    text = re.sub(r'[^a-z0-9\- ]', '', text)
    text = text.replace(' ', '-')
    # Github leaves multiple hyphens if there were multiple spaces, e.g. "Arrays & Hashing" -> "arrays--hashing"
    return text

lines = content.split('\n')
in_table = False
new_lines = []
for i, line in enumerate(lines):
    if line.startswith("| Category | Solved | Total | Progress |"):
        new_lines.append("| Category | Total | Solved | Progress |")
        in_table = True
    elif line.startswith("|----------|--------|-------|----------|"):
        new_lines.append("|----------|-------|--------|----------|")
    elif in_table and line.startswith("|"):
        parts = [p.strip() for p in line.split('|')][1:-1]
        if len(parts) == 4:
            cat, sol, tot, prog = parts
            if "**Total**" in cat:
                new_lines.append(f"| {cat} | **{tot.strip('*')}** | **{sol.strip('*')}** | {prog} |")
            else:
                slug = slugify(cat)
                link = f"[{cat}](#{slug})"
                new_lines.append(f"| {link} | {tot} | {sol} | {prog} |")
        else:
            new_lines.append(line)
            in_table = False
    else:
        if in_table and not line.startswith("|"):
            in_table = False
        new_lines.append(line)

content = '\n'.join(new_lines)

# 2. Fix the problems list
def repl_problem(m):
    cb = m.group(1)
    rest = m.group(2).strip()
    icon = m.group(3)
    return f"- {icon} {cb} {rest}"

content = re.sub(r'^- (\[[ x]\]) (.*?)\s*(🟢|🟡|🔴)\s*$', repl_problem, content, flags=re.MULTILINE)

# 3. Fix the video line
content = re.sub(r'^(\s+)\[🎬 Video\]\((.*?)\)', r'\1[🎬 Video explanation](\2)', content, flags=re.MULTILINE)

with open("overview.md", "w", encoding="utf-8") as f:
    f.write(content)
