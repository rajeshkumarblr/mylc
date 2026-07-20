import re

with open('overview.md', 'r') as f:
    lines = f.readlines()

# find sections and count [x]
sections = {}
current_section = None
for line in lines:
    m = re.match(r'^## (.*)', line)
    if m:
        current_section = m.group(1).strip()
        sections[current_section] = {'total': 0, 'done': 0}
    elif current_section and line.startswith('- '):
        if '[ ]' in line or '[x]' in line:
            sections[current_section]['total'] += 1
            if '[x]' in line:
                sections[current_section]['done'] += 1

# update table
in_table = False
total_done = 0
total_all = 0
for i in range(len(lines)):
    line = lines[i]
    if line.startswith('| ['):
        m = re.match(r'\| \[(.*?)\]\(.*?\) \| (\d+) \| (\d+) \|', line)
        if m:
            sec_name = m.group(1).strip()
            if sec_name in sections:
                d = sections[sec_name]['done']
                t = sections[sec_name]['total']
                pct = int((d / t) * 100) if t > 0 else 0
                green = int(pct / 10)
                white = 10 - green
                bar = '🟩' * green + '⬜' * white
                lines[i] = f"| [{sec_name}](#{sec_name.lower().replace(' ', '-').replace('&', '')}) | {t} | {d} | {bar} {pct}% |\n"
                total_done += d
                total_all += t
    elif line.startswith('| **Total**'):
        pct = int((total_done / total_all) * 100) if total_all > 0 else 0
        green = int(pct / 10)
        white = 10 - green
        bar = '🟩' * green + '⬜' * white
        lines[i] = f"| **Total** | **{total_all}** | **{total_done}** | **{bar} {pct}%** |\n"

with open('overview.md', 'w') as f:
    f.writelines(lines)
