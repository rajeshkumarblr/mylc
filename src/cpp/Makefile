# src/cpp/Makefile — top-level for C++
SUBDIRS := array linked_list sliding_window two_pointers

# From src/cpp → repo root
REPO_ROOT := $(abspath $(CURDIR)/../..)
CPP_BUILD := $(REPO_ROOT)/build/cpp

.PHONY: all clean $(SUBDIRS) run build prof

all: $(SUBDIRS)
$(SUBDIRS): ; $(MAKE) -C $@

# ---------------- Run / Build by number (e.g., make run 42) ----------------

# Find the category that contains lc<NUM>.cpp
define FIND_DIR
$(shell for d in $(SUBDIRS); do \
  test -f $$d/lc$(1).cpp && echo $$d && break; \
done)
endef

run:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
	  echo "Usage: make run <problem_number>"; exit 1; \
	fi; \
	NUM="$(word 2,$(MAKECMDGOALS))"; \
	DIR="$(call FIND_DIR,$(word 2,$(MAKECMDGOALS)))"; \
	if [ -z "$$DIR" ]; then \
	  echo "Could not find lc$$NUM.cpp in: $(SUBDIRS)"; exit 2; \
	fi; \
	$(MAKE) -C "$$DIR" run $$NUM

prof:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
	  echo "Usage: make prof <problem_number> [TOOL=perf|callgrind|massif]"; exit 1; \
	fi; \
	NUM="$(word 2,$(MAKECMDGOALS))"; \
	DIR=""; \
	for d in $(SUBDIRS); do \
	  if [ -f "$$d/lc$$NUM.cpp" ]; then DIR="$$d"; break; fi; \
	done; \
	if [ -z "$$DIR" ]; then \
	  echo "Could not find lc$$NUM.cpp in: $(SUBDIRS)"; exit 2; \
	fi; \
	$(MAKE) -C "$$DIR" prof $$NUM TOOL=$(TOOL)

# ---- Debug run by number (e.g., make dbg 42) ----
dbg:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
	  echo "Usage: make dbg <problem_number>"; exit 1; \
	fi; \
	NUM="$(word 2,$(MAKECMDGOALS))"; \
	DIR=""; \
	for d in $(SUBDIRS); do \
	  if [ -f "$$d/lc$$NUM.cpp" ]; then DIR="$$d"; break; fi; \
	done; \
	if [ -z "$$DIR" ]; then \
	  echo "Could not find lc$$NUM.cpp in: $(SUBDIRS)"; exit 2; \
	fi; \
	$(MAKE) -C "$$DIR" dbg $$NUM

build:
	@if [ -z "$(word 2,$(MAKECMDGOALS))" ]; then \
	  echo "Usage: make build <problem_number>"; exit 1; \
	fi; \
	NUM="$(word 2,$(MAKECMDGOALS))"; \
	DIR="$(call FIND_DIR,$(word 2,$(MAKECMDGOALS)))"; \
	if [ -z "$$DIR" ]; then \
	  echo "Could not find lc$$NUM.cpp in: $(SUBDIRS)"; exit 2; \
	fi; \
	$(MAKE) -C "$$DIR" lc$$NUM

# ---------------- Clean ----------------
# - "make clean"        -> clean all categories + remove all C++ binaries
# - "make clean 42"     -> remove only build/cpp/lc42 (no subdir cleans)

clean:
	@if [ -n "$(word 2,$(MAKECMDGOALS))" ]; then \
	  NUM="$(word 2,$(MAKECMDGOALS))"; \
	  BIN="$(CPP_BUILD)/lc$$NUM"; \
	  if [ -f "$$BIN" ]; then \
	    echo "Removing $$BIN"; rm -f "$$BIN"; \
	  else \
	    echo "Binary $$BIN not found"; \
	  fi; \
	else \
	  for d in $(SUBDIRS); do $(MAKE) -C $$d clean; done; \
	  rm -f $(CPP_BUILD)/* 2>/dev/null || true; \
	fi

# Swallow extra words like "42" so Make doesn't treat them as independent targets
%::
	@:
