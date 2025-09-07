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

.PHONY: run-array run-linked_list run-sliding_window run-tree run-two_pointers
run-array:          ; @for b in lc1 lc9;                                  do LC_SILENT=1 "$(BUILD_DIR)/$$b" >/dev/null || exit $$?; done
run-linked_list:    ; @for b in lc2 lc21;                                  do LC_SILENT=1 "$(BUILD_DIR)/$$b" >/dev/null || exit $$?; done
run-sliding_window: ; @for b in lc3 lc424 lc438 lc567;                      do LC_SILENT=1 "$(BUILD_DIR)/$$b" >/dev/null || exit $$?; done
run-tree:           ; @for b in lc94;                                      do LC_SILENT=1 "$(BUILD_DIR)/$$b" >/dev/null || exit $$?; done
run-two_pointers:   ; @for b in lc11 lc42;                                 do LC_SILENT=1 "$(BUILD_DIR)/$$b" >/dev/null || exit $$?; done


# ---- perf helpers ----
PERF_BIN ?= perf
PROF_DIR := $(REPO_ROOT)/build/prof/cpp
$(shell mkdir -p $(PROF_DIR) >/dev/null)

# perf a single binary: make perf-lc42  (writes perf.data + text report)
.PHONY: perf-%
perf-%: build
	@bin="$(BUILD_DIR)/$*"; \
	[ -x "$$bin" ] || { echo "No such binary: $$bin"; exit 1; }; \
	out="$(PROF_DIR)/$*.perf.data"; txt="$(PROF_DIR)/$*.perf.txt"; \
	echo "Recording: $$bin  ->  $$out"; \
	LC_SILENT=1 $(PERF_BIN) record -g -o "$$out" -- "$$bin" >/dev/null || exit $$?; \
	$(PERF_BIN) report -n --stdio -i "$$out" > "$$txt"; \
	echo "Report: $$txt"

# perf all in a category: make perf-array / perf-two_pointers / etc.
.PHONY: perf-array perf-linked_list perf-sliding_window perf-tree perf-two_pointers
perf-array:          ; @for b in lc1 lc9;                                  do $(MAKE) -s perf-$$b || exit $$?; done
perf-linked_list:    ; @for b in lc2 lc21;                                  do $(MAKE) -s perf-$$b || exit $$?; done
perf-sliding_window: ; @for b in lc3 lc424 lc438 lc567;                      do $(MAKE) -s perf-$$b || exit $$?; done
perf-tree:           ; @for b in lc94;                                      do $(MAKE) -s perf-$$b || exit $$?; done
perf-two_pointers:   ; @for b in lc11 lc42;                                 do $(MAKE) -s perf-$$b || exit $$?; done

clean:
	@for d in $(SUBDIRS); do \
		$(MAKE) -C $$d clean || true; \
	done
