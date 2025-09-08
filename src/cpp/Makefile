# === lc/src/cpp/Makefile =====================================================
# Flat naming: <id>.<desc>.cpp  (e.g., 104.maximum-depth-of-binary-tree.cpp)

SHELL := /bin/bash
.ONESHELL:
.SHELLFLAGS := -eu -o pipefail -c

ROOT          := $(abspath $(CURDIR)/../..)
SRC_DIR       := $(CURDIR)
BUILD_DIR     := $(ROOT)/build/cpp
SOLUTION_LINK := $(ROOT)/solution
LAST_PROF_ID  := $(BUILD_DIR)/.last_prof_id

PY ?= python3
BEAT := $(ROOT)/src/mk/leetcode_beat.py

CXX ?= g++
STD := -std=gnu++17
WARN := -Wall -Wextra -Wpedantic
INCLUDES := -I$(SRC_DIR) -I$(ROOT)

CXXFLAGS_DBG  := $(STD) $(WARN) -g -O0 $(INCLUDES)
CXXFLAGS_PROF := $(STD) $(WARN) -pg -O2 $(INCLUDES)
LDFLAGS :=
LDLIBS  :=

# Optional: override if you use another submit tool.
SUBMIT_CMD ?= leetcode submit

# --- Discover problems -------------------------------------------------------
PROBLEM_IDS := $(shell ls -1 $(SRC_DIR)/*.cpp 2>/dev/null | sed -E 's#.*/([0-9]+)\..*#\1#' | sort -n | uniq)
DEBUG_BINS  := $(addprefix $(BUILD_DIR)/lc,$(addsuffix .dbg,$(PROBLEM_IDS)))

# Resolve the source path for an ID (glob, not regex)
define SRC_FOR
$(firstword $(wildcard $(SRC_DIR)/$(1).*cpp))
endef

# Parse CLI numbers (ignore meta targets)
ARGS_NUM := $(filter-out all dbg prof run submit show clean clobber,$(MAKECMDGOALS))
RUN_ALL  := $(filter all,$(MAKECMDGOALS))

.DEFAULT_GOAL := all
.PHONY: all run dbg prof submit show clean clobber prof-show

# === Build all ===============================================================
all: $(DEBUG_BINS)
	@echo "✔ Built $(words $(DEBUG_BINS)) debug binaries."

# Build a debug bin given an ID: lc<ID>.dbg
$(BUILD_DIR)/lc%.dbg:
	@ID="$*"; SRC="$(call SRC_FOR,$*)"; \
	if [[ -z "$$SRC" ]]; then echo "✗ Source for $$ID not found under $(SRC_DIR)"; exit 2; fi; \
	mkdir -p "$(BUILD_DIR)"; \
	echo "→ Compiling $$SRC → $(BUILD_DIR)/lc$${ID}.dbg"; \
	$(CXX) $(CXXFLAGS_DBG) "$$SRC" -o "$(BUILD_DIR)/lc$${ID}.dbg" $(LDFLAGS) $(LDLIBS)

# === Debug one & link solution ==============================================
dbg: $(addprefix dbg-,$(ARGS_NUM))
	@[[ -n "$(ARGS_NUM)" ]] || echo "Usage: make dbg <id>"

dbg-%:
	@ID="$*"; SRC="$(call SRC_FOR,$*)"; \
	if [[ -z "$$SRC" ]]; then echo "✗ Source for $$ID not found"; exit 2; fi; \
	mkdir -p "$(BUILD_DIR)"; \
	echo "→ Compiling $$SRC → $(BUILD_DIR)/lc$${ID}.dbg"; \
	$(CXX) $(CXXFLAGS_DBG) "$$SRC" -o "$(BUILD_DIR)/lc$${ID}.dbg" $(LDFLAGS) $(LDLIBS); \
	ln -snf "$(BUILD_DIR)/lc$${ID}.dbg" "$(SOLUTION_LINK)"; \
	echo "→ Linked $(SOLUTION_LINK) -> $(BUILD_DIR)/lc$${ID}.dbg"

# === Run =====================================================================
# make run all  -> build (if needed) and run all debug bins in numeric order
# make run <id> -> build debug & run that one
# make run      -> run current solution symlink
run:
	@if [[ -n "$(RUN_ALL)" ]]; then \
	  $(MAKE) --no-print-directory all; \
	  echo "→ Running all debug binaries:"; \
	  set -e; for id in $(PROBLEM_IDS); do \
	    bin="$(BUILD_DIR)/lc$${id}.dbg"; \
	    echo "===== RUN $$bin ====="; "$$bin"; \
	  done; \
	elif [[ -n "$(ARGS_NUM)" ]]; then \
	  id="$(firstword $(ARGS_NUM))"; \
	  $(MAKE) --no-print-directory dbg-$$id; \
	  bin="$(BUILD_DIR)/lc$${id}.dbg"; \
	  echo "→ Running $$bin"; exec "$$bin"; \
	else \
	  if [[ ! -e "$(SOLUTION_LINK)" ]]; then \
	    echo "✗ No solution binary. Use 'make dbg <id>' first."; exit 2; \
	  fi; \
	  if [[ -L "$(SOLUTION_LINK)" && ! -e "$$(readlink $(SOLUTION_LINK))" ]]; then \
	    echo "✗ $(SOLUTION_LINK) is a broken symlink."; exit 2; \
	  fi; \
	  echo "→ Running $(SOLUTION_LINK)"; exec "$(SOLUTION_LINK)"; \
	fi

# Handy: make run-104
run-%:
	@$(MAKE) --no-print-directory dbg-$*; \
	BIN="$(BUILD_DIR)/lc$*.dbg"; \
	echo "→ Running $$BIN"; exec "$$BIN"

# === Profiling (gprof) =======================================================
# make prof <id> [...]  -> build with -pg, run, write lc<ID>.prof.txt
# make prof show        -> show last profiling report
prof:
	@if [[ -n "$(ARGS_NUM)" && "$(firstword $(ARGS_NUM))" != "show" ]]; then \
	  for id in $(ARGS_NUM); do $(MAKE) --no-print-directory prof-$$id; done; \
	fi

prof-%:
	@ID="$*"; SRC="$(call SRC_FOR,$*)"; \
	if [[ -z "$$SRC" ]]; then echo "✗ Source for $$ID not found"; exit 2; fi; \
	mkdir -p "$(BUILD_DIR)"; \
	echo "→ Compiling (profile) $$SRC → $(BUILD_DIR)/lc$${ID}.prof"; \
	$(CXX) $(CXXFLAGS_PROF) "$$SRC" -o "$(BUILD_DIR)/lc$${ID}.prof" $(LDFLAGS) $(LDLIBS); \
	echo "→ Running profiled binary to record gmon.out"; \
	( cd "$(BUILD_DIR)" && "./lc$${ID}.prof" >/dev/null 2>&1 || true ); \
	if [[ -f "$(BUILD_DIR)/gmon.out" ]]; then \
	  mv -f "$(BUILD_DIR)/gmon.out" "$(BUILD_DIR)/lc$${ID}.gmon.out"; \
	  echo "→ Generating gprof report: $(BUILD_DIR)/lc$${ID}.prof.txt"; \
	  gprof "$(BUILD_DIR)/lc$${ID}.prof" "$(BUILD_DIR)/lc$${ID}.gmon.out" > "$(BUILD_DIR)/lc$${ID}.prof.txt"; \
	  echo "$$ID" > "$(LAST_PROF_ID)"; \
	  echo "✔ Profile written to $(BUILD_DIR)/lc$${ID}.prof.txt"; \
	else \
	  echo "⚠ No gmon.out produced (program may have exited too early)."; \
	fi

# Show last profile report
show prof-show:
	@if [[ -f "$(LAST_PROF_ID)" ]]; then \
	  id="$$(cat "$(LAST_PROF_ID)")"; rpt="$(BUILD_DIR)/lc$${id}.prof.txt"; \
	  if [[ -f "$$rpt" ]]; then echo "===== $$rpt ====="; cat "$$rpt"; exit 0; fi; \
	fi; \
	last="$$(ls -1t $(BUILD_DIR)/lc*.prof.txt 2>/dev/null | head -n1)"; \
	if [[ -n "$$last" ]]; then echo "===== $$last ====="; cat "$$last"; \
	else echo "✗ No profile report found. Run 'make prof <id>' first."; exit 2; fi

# === Submit (build a clean file with header + code block only) ==============
submit: $(addprefix submit-,$(ARGS_NUM))
	@if [[ -z "$(ARGS_NUM)" ]]; then echo "Usage: make submit <id>"; exit 2; fi

submit-%:
	@ID="$*"
	SRC="$(call SRC_FOR,$*)"
	if [[ -z "$$SRC" ]]; then
	  echo "✗ Source for $$ID not found"; exit 2
	fi

	mkdir -p "$(BUILD_DIR)"
	SNIP="$(BUILD_DIR)/lc$${ID}.submit.cpp"
	FULL="$(BUILD_DIR)/lc$${ID}.submit.full.cpp"

	# 1) Extract only the code between markers (for your records)
	if ! awk '/@lc code=start/{flag=1;next} /@lc code=end/{flag=0} flag' "$$SRC" > "$$SNIP"; then
	  echo "✗ Failed to extract code block for $$ID"; exit 2
	fi
	if [[ ! -s "$$SNIP" ]]; then
	  echo "✗ No code between @lc code markers in $$SRC"; exit 2
	fi
	echo "→ Extracted solution to $$SNIP"

	# 2) Build a CLEAN submit file with header + markers ONLY (no local includes)
	HDR_LINE="$$(grep -m1 -E '^//[[:space:]]*@lc[[:space:]]+app=leetcode' "$$SRC" || true)"
	if [[ -z "$$HDR_LINE" ]]; then
	  HDR_LINE="// @lc app=leetcode id=$$ID lang=cpp"
	fi

	{
	  echo "$$HDR_LINE"
	  echo "// @lc code=start"
	  cat "$$SNIP"
	  echo "// @lc code=end"
	} > "$$FULL"

	echo "→ Prepared clean submit file: $$FULL"

	# 3) Submit the CLEAN file
	if ! command -v leetcode >/dev/null 2>&1; then
	  echo "⚠ 'leetcode' CLI not found. To submit manually run:"
	  echo "   leetcode submit \"$$FULL\""
	  exit 0
	fi
	echo "→ Submitting with: leetcode submit $$FULL"
	leetcode submit "$$FULL"
	# Fetch beat ratio (GraphQL via stdlib Python; no extra deps)
	if [ -x "$(BEAT)" ]; then
	  $(PY) "$(BEAT)" --id "$$ID" --src-dir "$(SRC_DIR)" || true
	else
	  echo "ℹ To auto-fetch beat ratio, save the script at: $(BEAT)"
	fi

.PHONY: beat
beat:
	@if [ -z "$(ARGS_NUM)" ]; then echo "Usage: make beat <id>"; exit 2; fi
	$(PY) "$(BEAT)" --id "$(firstword $(ARGS_NUM))" --src-dir "$(SRC_DIR)"	

# === Convenience: numeric-only builds debug (e.g., `make 104`) ==============
%:
	@case "$@" in \
	  (*[!0-9]* ) echo "Unknown target '$@'"; exit 2 ;; \
	  (*) $(MAKE) --no-print-directory dbg-$@ ;; \
	esac

# === Cleanup =================================================================
clean:
	@mkdir -p "$(BUILD_DIR)"
	@echo "Cleaning $(BUILD_DIR):"
	@find "$(BUILD_DIR)" -maxdepth 1 -type f \
	  \( -name 'lc*.dbg' -o -name 'lc*.prof' -o -name 'lc*.gmon.out' -o -name 'lc*.prof.txt' -o -name 'lc*.submit.cpp' \) \
	  -print -delete 2>/dev/null || true

clobber: clean
	@rm -rf "$(BUILD_DIR)" 2>/dev/null || true
	@rm -f "$(SOLUTION_LINK)" 2>/dev/null || true
	@echo "✔ Cleaned."
# ============================================================================
