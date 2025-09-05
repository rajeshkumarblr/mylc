# src/mk/dir.mk
SHELL := /bin/bash
.ONESHELL:
.DELETE_ON_ERROR:

# Expect from includer:
#   SUBDIRS := array linked_list sliding_window two_pointers
#   LANG    := cpp
# Optional from includer:
#   REPO_ROOT := $(abspath $(CURDIR)/../..)
REPO_ROOT ?= $(abspath $(CURDIR)/../..)

# Build roots per language
BUILD_ROOT := $(REPO_ROOT)/build
CPP_BUILD  := $(BUILD_ROOT)/cpp
GO_BUILD   := $(BUILD_ROOT)/go
PY_BUILD   := $(BUILD_ROOT)/python

.PHONY: all clean $(SUBDIRS) run build t dbg

all: $(SUBDIRS)
$(SUBDIRS): ; $(MAKE) -C $@

# ---- helpers ----
# Find category that contains lc<NUM>.<ext>
define FIND_DIR
$(shell for d in $(SUBDIRS); do \
  if [ -f $$d/lc$(1).$(2) ]; then echo $$d; break; fi; \
done)
endef

# ---- run/build/clean by number (two-word form e.g. "make run 42") ----
run:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
	  echo "Usage: make run <problem_number>"; exit 1; \
	fi; \
	NUM="$(word 2,$(MAKECMDGOALS))"; \
	case "$(LANG)" in \
	  cpp)   EXT=cpp ; DIR="$(call FIND_DIR,$(word 2,$(MAKECMDGOALS)),cpp)" ;; \
	  go)    EXT=go  ; DIR="$(call FIND_DIR,$(word 2,$(MAKECMDGOALS)),go)"  ;; \
	  python)EXT=py  ; DIR="$(call FIND_DIR,$(word 2,$(MAKECMDGOALS)),py)"  ;; \
	  *)     echo "Unknown LANG=$(LANG)"; exit 2 ;; \
	esac; \
	if [ -z "$$DIR" ]; then \
	  echo "Could not find lc$$NUM.$$EXT in: $(SUBDIRS)"; exit 2; \
	fi; \
	$(MAKE) -C "$$DIR" run $$NUM

build:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
	  echo "Usage: make build <problem_number>"; exit 1; \
	fi; \
	NUM="$(word 2,$(MAKECMDGOALS))"; \
	case "$(LANG)" in \
	  cpp)   EXT=cpp ; DIR="$(call FIND_DIR,$(word 2,$(MAKECMDGOALS)),cpp)" ;; \
	  go)    EXT=go  ; DIR="$(call FIND_DIR,$(word 2,$(MAKECMDGOALS)),go)"  ;; \
	  python)EXT=py  ; DIR="$(call FIND_DIR,$(word 2,$(MAKECMDGOALS)),py)"  ;; \
	  *)     echo "Unknown LANG=$(LANG)"; exit 2 ;; \
	esac; \
	if [ -z "$$DIR" ]; then \
	  echo "Could not find lc$$NUM.$$EXT in: $(SUBDIRS)"; exit 2; \
	fi; \
	$(MAKE) -C "$$DIR" lc$$NUM

# timed run: "make t 42"
t:
	@$(MAKE) run $(word 2,$(MAKECMDGOALS)) MODE=fast TIME=1

# debug-sanitized build+run: "make dbg 42"
dbg:
	@$(MAKE) run $(word 2,$(MAKECMDGOALS)) MODE=dbg

# clean all vs clean a specific number: "make clean 42"
clean:
	@if [ -n "$(word 2,$(MAKECMDGOALS))" ]; then \
	  NUM="$(word 2,$(MAKECMDGOALS))"; \
	  case "$(LANG)" in \
	    cpp) BIN="$(CPP_BUILD)/lc$$NUM" ;; \
	    go)  BIN="$(GO_BUILD)/lc$$NUM"  ;; \
	    *)   BIN="" ;; \
	  esac; \
	  if [ -n "$$BIN" ] && [ -f "$$BIN" ]; then \
	    echo "Removing $$BIN"; rm -f "$$BIN"; \
	  else \
	    echo "Binary $$BIN not found"; \
	  fi; \
	else \
	  for d in $(SUBDIRS); do $(MAKE) -C $$d clean; done; \
	  rm -f $(CPP_BUILD)/* 2>/dev/null || true; \
	  rm -f $(GO_BUILD)/*  2>/dev/null || true; \
	fi

# swallow extra goals like "42" to avoid unknown target errors
%::
	@:
