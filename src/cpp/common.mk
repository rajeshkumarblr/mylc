# src/cpp/common.mk — included by src/cpp/<category>/Makefile via ../../common.mk
SHELL := /bin/bash
.ONESHELL:
.DELETE_ON_ERROR:

# From src/cpp/<category> → repo root
REPO_ROOT := $(abspath $(CURDIR)/../../..)
BUILD_DIR := $(REPO_ROOT)/build/cpp

CXX      ?= g++
# Release: -O2 (keep -g if you like symbols in release)
CXXFLAGS_REL := -std=c++17 -O2 -g -Wall -Wextra -Wshadow -Wconversion \
                -I$(REPO_ROOT)/src/common/cpp -I$(REPO_ROOT)
# Debug: no -O2 so you can see everything while debugging
CXXFLAGS_DBG := -std=c++17 -O0 -g -fno-omit-frame-pointer \
                -Wall -Wextra -Wshadow -Wconversion \
                -I$(REPO_ROOT)/src/common/cpp -I$(REPO_ROOT)

SRC    := $(wildcard *.cpp)
NAMES  := $(patsubst %.cpp,%,$(notdir $(SRC)))

# Per-problem outputs
BINS_REL := $(addprefix $(BUILD_DIR)/,$(NAMES))
BINS_DBG := $(addsuffix .dbg,$(BINS_REL))
BINS     := $(BINS_REL) $(BINS_DBG)

.PHONY: all clean run dbg

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

clean:
	@rm -f $(BINS)

# swallow numeric arg (e.g., "make run 42")
%::
	@:
