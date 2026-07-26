---
name: sync-lc-progress
description: Updates the overview, generates dashboard data, and commits and pushes all changes to the repository.
---

# Sync LeetCode Progress

When the user asks to sync their progress, commit and push, or update the overview and dashboard, follow these exact steps without asking for further confirmation:

1. Execute `python3 scripts/generate_overview.py` from the workspace root to update `overview.md`.
2. Execute `python3 scripts/generate_dashboard_data.py` from the workspace root to update `dashboard/public/data.json`.
3. Add the changed files to git (`git add .` or specifically target the modified cpp/md/json files).
4. Create a descriptive commit message based on the problem just solved (e.g., `feat: solved LC 417 Pacific Atlantic Water Flow`).
5. Execute `git commit -m "<message>"` followed by `git push origin main`.
6. Confirm to the user that the dashboard and overview are updated, and changes are pushed.
