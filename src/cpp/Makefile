SHELL := /bin/bash
.ONESHELL:
.DELETE_ON_ERROR:

# repo root from src/cpp/
REPO_ROOT := $(abspath $(CURDIR)/../..)
BUILD_DIR := $(REPO_ROOT)/build/cpp
REPORT_DIR := $(REPO_ROOT)/build/reports/cpp
REPORT := $(REPORT_DIR)/summary.txt

# C++ problem categories (folders under src/cpp/)
SUBDIRS := array linked_list sliding_window tree two_pointers

.PHONY: all build run-all run-all-dbg list clean

# Build everything in all subdirs (release + debug per problem)
all build:
	@for d in $(SUBDIRS); do \
		echo "== Building $$d =="; \
		$(MAKE) -C $$d all || exit $$?; \
	done

# List all built release binaries
list:
	@find "$(BUILD_DIR)" -maxdepth 1 -type f -executable -name 'lc*' ! -name '*.dbg' 2>/dev/null | sort

# Run ALL release binaries with a compact PASS/FAIL summary
run-all: build
	@mkdir -p "$(REPORT_DIR)"
	@echo "== LC run-all report ==" > "$(REPORT)"
	@pass=0; fail=0; total=0; \
	for bin in $$(find "$(BUILD_DIR)" -maxdepth 1 -type f -executable -name 'lc*' ! -name '*.dbg' 2>/dev/null | sort); do \
		name=$$(basename $$bin); total=$$((total+1)); \
		printf "→ %-14s " "$$name"; \
		if LC_SILENT=1 "$$bin" >/dev/null; then \
			echo "PASS"; echo "$$name PASS" >>"$(REPORT)"; pass=$$((pass+1)); \
		else \
			echo "FAIL"; echo "$$name FAIL" >>"$(REPORT)"; fail=$$((fail+1)); \
		fi; \
	done; \
	echo "----" | tee -a "$(REPORT)"; \
	echo "PASS=$$pass FAIL=$$fail TOTAL=$$total" | tee -a "$(REPORT)"; \
	# Make returns nonzero if any failed:
	test $$fail -eq 0

# Run ALL debug binaries (handy if you want assertions/ASan etc.)
run-all-dbg: build
	@mkdir -p "$(REPORT_DIR)"
	@echo "== LC run-all-dbg report ==" > "$(REPORT)"
	@pass=0; fail=0; total=0; \
	for bin in $$(find "$(BUILD_DIR)" -maxdepth 1 -type f -executable -name 'lc*.dbg' 2>/dev/null | sort); do \
		name=$$(basename $$bin); total=$$((total+1)); \
		printf "→ %-14s " "$$name"; \
		if LC_SILENT=1 "$$bin" >/dev/null; then \
			echo "PASS"; echo "$$name PASS" >>"$(REPORT)"; pass=$$((pass+1)); \
		else \
			echo "FAIL"; echo "$$name FAIL" >>"$(REPORT)"; fail=$$((fail+1)); \
		fi; \
	done; \
	echo "----" | tee -a "$(REPORT)"; \
	echo "PASS=$$pass FAIL=$$fail TOTAL=$$total" | tee -a "$(REPORT)"; \
	test $$fail -eq 0

clean:
	@for d in $(SUBDIRS); do \
		$(MAKE) -C $$d clean || true; \
	done
