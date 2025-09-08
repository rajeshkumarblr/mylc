#!/usr/bin/env node
import { LeetCode, Credential } from "leetcode-query";
import fs from "fs"; import path from "path";

const id = process.argv[2];
if (!id) { console.error("Usage: node leetcode_beat.mjs <id>"); process.exit(2); }

const home = process.env.HOME || process.env.USERPROFILE || "";
const candidates = [
  path.join(home, ".leetcode", "user.json"),
  path.join(home, ".lc", "leetcode", "user.json"),
];

let cookie = null;
for (const p of candidates) {
  try {
    const j = JSON.parse(fs.readFileSync(p, "utf8"));
    cookie = j.cookie || j.cookies ||
             `LEETCODE_SESSION=${j.LEETCODE_SESSION || j.session}; csrftoken=${j.csrftoken || j.sessionCSRF || j.csrf}`;
    if (cookie) break;
  } catch { /* keep trying */ }
}
if (!cookie) { console.error("✗ No LeetCode cookie found in ~/.leetcode or ~/.lc/leetcode"); process.exit(3); }

const cred = new Credential(); await cred.init(cookie);
const lc = new LeetCode(cred);

// get your most recent submissions and pick the one matching the frontend id
const { submissions } = await lc.submissions({ limit: 40, offset: 0 });
const mine = (submissions || []).find(s => String(s.question?.questionFrontendId) === String(id));
if (!mine) { console.error(`✗ No recent submission found for id ${id}`); process.exit(4); }

const det = await lc.submission_detail(mine.id);
const rp = det.runtimePercentile, mp = det.memoryPercentile;
const rt = det.runtimeDisplay || det.runtime, mem = det.memoryDisplay || det.memory;

const pct = x => (typeof x === "number" ? `${x.toFixed(1)}%` : (x ?? "?"));
console.log(`→ Beat ratio: runtime ${pct(rp)}${rt ? ` (time ${rt})` : ""}  |  memory ${pct(mp)}${mem ? ` (mem ${mem})` : ""}`);
