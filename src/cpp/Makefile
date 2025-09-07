# src/cpp/Makefile — flat layout, descriptive filenames
SHELL := /bin/bash
.ONESHELL:
.DELETE_ON_ERROR:

REPO_ROOT := $(abspath $(CURDIR)/../..)
SRC_DIR   := $(CURDIR)
BUILD_DIR := $(REPO_ROOT)/build/cpp
REPORT_DIR := $(REPO_ROOT)/build/reports/cpp
REPORT     := $(REPORT_DIR)/summary.txt
TAGS_JSON  := $(REPO_ROOT)/tags.json
PROF_DIR   := $(REPO_ROOT)/build/prof/cpp

$(shell mkdir -p "$(BUILD_DIR)" "$(REPORT_DIR)" "$(PROF_DIR)" >/dev/null)

# --- compiler & flags ---
CXX ?= g++
INC_DIRS := -I$(REPO_ROOT)/src/cpp -I$(REPO_ROOT)

CXXFLAGS_REL := -std=c++17 -O2 -g -fno-omit-frame-pointer -MMD -MP \
                -Wall -Wextra -Wshadow -Wconversion $(INC_DIRS)

CXXFLAGS_DBG := -std=c++17 -O0 -g -fno-omit-frame-pointer -MMD -MP \
                -fsanitize=address,undefined -fno-sanitize-recover=all \
                -Wall -Wextra -Wshadow -Wconversion $(INC_DIRS)

# --- discover sources ---
SOURCES_BN := $(notdir $(wildcard $(SRC_DIR)/*.cpp))  # e.g. 42.trapping-rain-water.cpp
# Extract numeric id (first token before '.') from each source name
IDS       := $(foreach f,$(SOURCES_BN),$(firstword $(subst ., ,$(f))))  # e.g. 42
# Map ids to binaries lc<id>
BIN_NAMES := $(addprefix lc,$(IDS))
BINS      := $(addprefix $(BUILD_DIR)/,$(BIN_NAMES))
BINS_DBG  := $(addsuffix .dbg,$(BINS))

.PHONY: all build dbg clean list run-all run-all-dbg run-tag perf-% perf-tag asan-run
all: build dbg
build: $(BINS)
dbg:   $(BINS_DBG)

# --- per-file rules (generate from (id, file) pairs) ---
# Find the source file for an id (pattern: "<id>.*.cpp")
define SRC_FOR_ID
$(firstword $(wildcard $(SRC_DIR)/$(1).*\.cpp))
endef

define COMPILE_tpl
$(BUILD_DIR)/lc$(1): $(call SRC_FOR_ID,$(1))
	$$(CXX) $$(CXXFLAGS_REL) $$< -o $$@
$(BUILD_DIR)/lc$(1).dbg: $(call SRC_FOR_ID,$(1))
	$$(CXX) $$(CXXFLAGS_DBG) $$< -o $$@
endef

# Emit concrete rules for every id
$(foreach id,$(IDS),$(eval $(call COMPILE_tpl,$(id))))

list:
	@printf '%s\n' $(BIN_NAMES) | sort

# ---------- run-all (release) ----------
run-all: build
	@echo "== LC run-all report ==" > "$(REPORT)"
	@pass=0; fail=0; total=0; \
	for bin in $(BINS); do \
		name=$$(basename $$bin); total=$$((total+1)); \
		printf "→ %-12s " "$$name"; \
		if LC_SILENT=1 "$$bin" >/dev/null; then \
			echo "PASS"; echo "$$name PASS" >>"$(REPORT)"; pass=$$((pass+1)); \
		else \
			echo "FAIL"; echo "$$name FAIL" >>"$(REPORT)"; fail=$$((fail+1)); \
		fi; \
	done; \
	echo "----" | tee -a "$(REPORT)"; \
	echo "PASS=$$pass FAIL=$$fail TOTAL=$$total" | tee -a "$(REPORT)"; \
	test $$fail -eq 0

# ---------- run-all (debug) ----------
run-all-dbg: dbg
	@echo "== LC run-all-dbg report ==" > "$(REPORT)"
	@pass=0; fail=0; total=0; \
	for bin in $(BINS_DBG); do \
		name=$$(basename $$bin); total=$$((total+1)); \
		printf "→ %-16s " "$$name"; \
		if LC_SILENT=1 "$$bin" >/dev/null; then \
			echo "PASS"; echo "$$name PASS" >>"$(REPORT)"; pass=$$((pass+1)); \
		else \
			echo "FAIL"; echo "$$name FAIL" >>"$(REPORT)"; fail=$$((fail+1)); \
		fi; \
	done; \
	echo "----" | tee -a "$(REPORT)"; \
	echo "PASS=$$pass FAIL=$$fail TOTAL=$$total" | tee -a "$(REPORT)"; \
	test $$fail -eq 0

# ---------- tag-based runs (uses tags.json with ids like lc42) ----------
TAG ?= array
PROBLEMS_FOR_TAG = $(shell python3 $(REPO_ROOT)/scripts/tags.py --file $(TAGS_JSON) --lang cpp --tag $(TAG))

run-tag: build
	@probs="$(PROBLEMS_FOR_TAG)"; \
	if [ -z "$$probs" ]; then echo "No problems for tag '$(TAG)'"; exit 0; fi; \
	pass=0; fail=0; total=0; \
	for id in $$probs; do \
		bin="$(BUILD_DIR)/$$id"; \
		[ -x "$$bin" ] || { echo "skip $$id (no binary)"; continue; } ; \
		printf "→ %-12s " "$$id"; \
		if LC_SILENT=1 "$$bin" >/dev/null; then echo PASS; pass=$$((pass+1)); else echo FAIL; fail=$$((fail+1)); fi; \
		total=$$((total+1)); \
	done; \
	echo "----"; echo "PASS=$$pass FAIL=$$fail TOTAL=$$total"; \
	test $$fail -eq 0

# ---------- perf ----------
PERF_BIN ?= perf

perf-%: build
	@bin="$(BUILD_DIR)/$*"; \
	[ -x "$$bin" ] || { echo "No such binary: $$bin"; exit 1; }; \
	out="$(PROF_DIR)/$*.perf.data"; txt="$(PROF_DIR)/$*.perf.txt"; \
	echo "Recording: $$bin  ->  $$out"; \
	LC_SILENT=1 $(PERF_BIN) record -g -o "$$out" -- "$$bin" >/dev/null || exit $$?; \
	$(PERF_BIN) report -n --stdio -i "$$out" > "$$txt"; \
	echo "Report: $$txt"

perf-tag: build
	@probs="$(PROBLEMS_FOR_TAG)"; \
	if [ -z "$$probs" ]; then echo "No problems for tag '$(TAG)'"; exit 0; fi; \
	for id in $$probs; do $(MAKE) -s perf-$$id || exit $$?; done

# ---------- sanitizers ----------
asan-run: dbg
	@ASAN_OPTIONS='detect_leaks=1:halt_on_error=1:strict_string_checks=1:alloc_dealloc_mismatch=1:fast_unwind_on_malloc=0:detect_stack_use_after_return=1' \
	UBSAN_OPTIONS='print_stacktrace=1:halt_on_error=1' \
	$(MAKE) -s run-all-dbg

clean:
	@rm -f $(BINS) $(BINS_DBG) $(BUILD_DIR)/*.d
