#!/usr/bin/env bash
# Smoke test for the LeetCode harness
# - Cleans and builds C++ and Go runners
# - Exercises ./run with list, all, category, and single-problem modes for both languages
# - Optional: submission tests when TEST_SUBMIT=1 and `leetcode` CLI is available

set -Euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
cd "$ROOT"

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

ok_count=0
fail_count=0
skip_count=0

log() { echo -e "${YELLOW}==>${NC} $*"; }
pass() { echo -e "${GREEN}PASS${NC} - $*"; ((ok_count++)); }
fail() { echo -e "${RED}FAIL${NC} - $*"; ((fail_count++)); }
skip() { echo -e "${YELLOW}SKIP${NC} - $*"; ((skip_count++)); }

run_and_expect() {
  # Args: description, command, expected_regex (optional)
  local desc="$1"; shift
  local cmd=("$@")
  local expect=""
  if [[ ${#cmd[@]} -ge 2 && ${cmd[-2]} == "--EXPECT--" ]]; then
    expect="${cmd[-1]}"; unset 'cmd[-1]'; unset 'cmd[-1]'
  fi
  log "$desc"
  local out ec
  set +e
  out=$("${cmd[@]}" 2>&1)
  ec=$?
  echo "$out"
  if [[ $ec -ne 0 ]]; then
    fail "$desc (exit=$ec)"
    return 1
  fi
  if [[ -n "$expect" ]]; then
    if echo "$out" | grep -Eiq -- "$expect"; then
      pass "$desc"
    else
      fail "$desc (missing pattern: $expect)"
      return 1
    fi
  else
    pass "$desc"
  fi
}

# 1) Validate Makefiles and clean builds
log "Top-level make clean"
run_and_expect "Top-level clean" make -C "$ROOT" clean

log "Top-level make default (may build language-specific or no-op)"
run_and_expect "Top-level make" make -C "$ROOT"

log "Cleaning previous builds"
rm -rf "$ROOT/build/cpp" "$ROOT/build/go" || true

run_and_expect "Build C++ runner" make -C "$ROOT/src/cpp" clean all
if [[ -x "$ROOT/build/cpp/runner" ]]; then
  pass "C++ runner exists"
else
  fail "C++ runner missing"
fi

HAVE_GO=0
if command -v go >/dev/null 2>&1; then HAVE_GO=1; fi
if [[ $HAVE_GO -eq 1 ]]; then
  run_and_expect "Build Go runner" make -C "$ROOT/src/go" clean all
  if [[ -x "$ROOT/build/go/runner" ]]; then
    pass "Go runner exists"
  else
    fail "Go runner missing"
  fi
else
  skip "Go toolchain not found; skipping Go build and run tests"
fi

# 2) Run modes - C++
run_and_expect "List problems/categories" "$ROOT/run" -L --EXPECT-- "^Categories:"
run_and_expect "Run all (C++)" "$ROOT/run" -a --EXPECT-- "Final Result: PASS"
run_and_expect "Run category tree (C++)" "$ROOT/run" -c tree --EXPECT-- "Final Result: PASS"
run_and_expect "Run single 94 (C++)" "$ROOT/run" -p 94 --EXPECT-- "Final Result: PASS"

# 3) Run modes - Go
if [[ $HAVE_GO -eq 1 ]]; then
  run_and_expect "Run category sliding_window (Go)" "$ROOT/run" -l go -c sliding_window --EXPECT-- "Final Result: PASS"
  run_and_expect "Run single 567 (Go)" "$ROOT/run" -l go -p 567 --EXPECT-- "Final Result: PASS"
else
  skip "Go run tests"
fi

# 4) Optional submit tests
if [[ "${TEST_SUBMIT:-0}" == "1" ]] && command -v leetcode >/dev/null 2>&1; then
  log "Optional submit tests enabled (TEST_SUBMIT=1)"
  run_and_expect "Submit 9 (C++)" "$ROOT/run" -s 9 -l cpp
  if [[ $HAVE_GO -eq 1 ]]; then
    run_and_expect "Submit 567 (Go)" "$ROOT/run" -s 567 -l go
  else
    skip "Go submit test"
  fi
else
  log "Skipping submit tests (set TEST_SUBMIT=1 and install 'vsc-leetcode-cli' to enable)"
fi

# Summary
log "Summary: ${ok_count} passed, ${fail_count} failed, ${skip_count} skipped"
if [[ $fail_count -gt 0 ]]; then
  echo -e "${RED}Some checks failed.${NC}" >&2
  exit 1
else
  echo -e "${GREEN}All checks passed.${NC}"
fi
