# src/cpp/common.mk — included by src/cpp/<category>/Makefile via ../../common.mk
SHELL := /bin/bash
.ONESHELL:
.DELETE_ON_ERROR:

# From src/cpp/<category> → repo root
REPO_ROOT := $(abspath $(CURDIR)/../../..)
BUILD_DIR := $(REPO_ROOT)/build/cpp

CXX      ?= g++
# Release: -O2 (keep -g if you like symbols in release)
CXXFLAGS_REL := -std=c++17 -O2 -g -fno-omit-frame-pointer \
                -Wall -Wextra -Wshadow -Wconversion \
                -I$(REPO_ROOT)/src/cpp/inc
# Debug: no -O2 so you can see everything while debugging
CXXFLAGS_DBG := -std=c++17 -O0 -g -fno-omit-frame-pointer \
                -Wall -Wextra -Wshadow -Wconversion \
                -I$(REPO_ROOT)/src/cpp/inc

SRC    := $(wildcard *.cpp)
NAMES  := $(patsubst %.cpp,%,$(notdir $(SRC)))

# Per-problem outputs
BINS_REL := $(addprefix $(BUILD_DIR)/,$(NAMES))
BINS_DBG := $(addsuffix .dbg,$(BINS_REL))
BINS     := $(BINS_REL) $(BINS_DBG)

.PHONY: all clean run dbg prof

all: $(BUILD_DIR) $(BINS)

$(BUILD_DIR):
	@mkdir -p $@

# Build release binary: build/cpp/<name>
$(BUILD_DIR)/%: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS_REL) $< -o $@

# Build debug binary: build/cpp/<name>.dbg
$(BUILD_DIR)/%.dbg: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS_DBG) $< -o $@

# Convenience target: `make lc42` builds BOTH (release + dbg) and
# updates repo-root `solution` symlink to the dbg binary.
%: %.cpp | $(BUILD_DIR)
	@$(MAKE) $(BUILD_DIR)/$@       # release
	@$(MAKE) $(BUILD_DIR)/$@.dbg   # debug
	@ln -sf "$(BUILD_DIR)/$@.dbg" "$(REPO_ROOT)/solution"
	@echo "Linked $(REPO_ROOT)/solution -> $(BUILD_DIR)/$@.dbg"

# `make run 42` -> builds both then runs RELEASE (build/cpp/lc42)
run:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
	  echo "Usage: make run <problem_number>"; exit 1; \
	fi; \
	NUM="$(word 2,$(MAKECMDGOALS))"; \
	$(MAKE) lc$$NUM; \
	"$(BUILD_DIR)/lc$$NUM"

# `make dbg 42` -> builds both then runs DEBUG (build/cpp/lc42.dbg)
dbg:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
	  echo "Usage: make dbg <problem_number>"; exit 1; \
	fi; \
	NUM="$(word 2,$(MAKECMDGOALS))"; \
	$(MAKE) lc$$NUM; \
	"$(BUILD_DIR)/lc$$NUM.dbg"

# ---- Profiling ----
# Usage:
#   make prof <num>                # default TOOL=perf
#   make prof <num> TOOL=callgrind # Valgrind callgrind
#   make prof <num> TOOL=massif    # Valgrind massif (heap)
#
# Outputs:
#   build/prof/cpp/lc<num>.perf.data      (perf)
#   build/prof/cpp/callgrind.out.lc<num>  (callgrind)
#   build/prof/cpp/massif.out.lc<num>     (massif)

PROF_DIR := $(REPO_ROOT)/build/prof/cpp
PERF_BIN ?= perf

prof:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
	  echo "Usage: make prof <problem_number> [TOOL=perf|callgrind|massif]"; exit 1; \
	fi; \
	NUM="$(word 2,$(MAKECMDGOALS))"; \
	$(MAKE) lc$$NUM; \
	mkdir -p "$(PROF_DIR)"; \
	TOOL="$${TOOL:-perf}"; \
	if [ "$$TOOL" = "perf" ]; then \
	  echo "==> Running perf on lc$$NUM (release)"; \
	  $(PERF_BIN) record -g --call-graph dwarf \
	    -o "$(PROF_DIR)/lc$$NUM.perf.data" "$(BUILD_DIR)/lc$$NUM"; \
	  echo "Perf data: $(PROF_DIR)/lc$$NUM.perf.data"; \
	  echo "View with: $(PERF_BIN) report -i $(PROF_DIR)/lc$$NUM.perf.data"; \
	elif [ "$$TOOL" = "callgrind" ]; then \
	  echo "==> Running callgrind on lc$$NUM (release)"; \
	  valgrind --tool=callgrind --callgrind-out-file="$(PROF_DIR)/callgrind.out.lc$$NUM" \
	    "$(BUILD_DIR)/lc$$NUM"; \
	  echo "Open in kcachegrind: $(PROF_DIR)/callgrind.out.lc$$NUM"; \
	elif [ "$$TOOL" = "massif" ]; then \
	  echo "==> Running massif on lc$$NUM (release)"; \
	  valgrind --tool=massif --massif-out-file="$(PROF_DIR)/massif.out.lc$$NUM" \
	    "$(BUILD_DIR)/lc$$NUM"; \
	  echo "View with: ms_print $(PROF_DIR)/massif.out.lc$$NUM"; \
	else \
	  echo "Unknown TOOL=$$TOOL (expected: perf|callgrind|massif)"; exit 2; \
	fi

clean:
	@rm -f $(BINS)

# swallow numeric arg (e.g., "make run 42")
%::
	@:
