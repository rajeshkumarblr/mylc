# Flat-structure Go harness mirroring your C++ UX.
# Examples:
#   make 42                      # build & run 42.*.go
#   make run NUM=42              # build & run explicitly
#   make stress NUM=42 N=100000  # stress a single problem
#   make dbg NUM=42              # build -N -l & run under Delve
#   make race NUM=42             # run with -race
#   make build-all               # build all problems
#   make run-all [ITERS=1]       # run all problems, summary at end
#   make fmt | vet | clean

SHELL := /bin/bash
GO    ?= go
DLV   ?= dlv

BIN_DIR := ../../build/go

GO_SRCS := $(sort $(wildcard *.go))
CENTRAL_MAIN := main.go
UTILS := lc_test_utils.go
CENTRAL_BIN := $(BIN_DIR)/runner

# Build the central runner with all solution files + utils
.PHONY: all
all: $(BIN_DIR)
	@set -euo pipefail; \
	if [ ! -f "$(CENTRAL_MAIN)" ]; then echo "main.go not found"; exit 1; fi; \
	if [ ! -f "$(UTILS)" ]; then echo "lc_test_utils.go not found"; exit 1; fi; \
	$(GO) mod tidy; \
	echo "==> Building central runner: $(CENTRAL_BIN)"; \
	$(GO) build -o "$(CENTRAL_BIN)" $(CENTRAL_MAIN) $(UTILS) $(filter-out $(CENTRAL_MAIN) $(UTILS),$(GO_SRCS)); \
	echo "Build-all: done."

# Run all problems using the central runner
ITERS ?= 1
.PHONY: run-all
run-all: all
	@echo "==> Running all problems via central runner"
	REPO_ROOT=$(realpath ../..) LC_STRESS_ITERS=$(ITERS) "$(CENTRAL_BIN)"

DEFAULT_GOAL := help

.PHONY: run
run:
	@ARG=$(word 2,$(MAKECMDGOALS)); \
	if [ -z "$$ARG" ]; then \
		echo "Usage: make run <problem_no|all|category>"; exit 1; \
	fi; \
	$(MAKE) build-all; \
	CATEGORIES="two_pointer sliding_window hash list misc tree"; \
	   if [ "$$ARG" = "all" ]; then \
		   echo "==> Running all problems via central runner"; \
		   REPO_ROOT=$(realpath ../..) "$(CENTRAL_BIN)"; \
	   elif echo "$$CATEGORIES" | grep -wq "$$ARG"; then \
		   echo "==> Running category $$ARG via central runner"; \
		   REPO_ROOT=$(realpath ../..) LC_CATEGORY=$$ARG "$(CENTRAL_BIN)"; \
	   else \
		   echo "==> Running problem $$ARG via central runner"; \
		   REPO_ROOT=$(realpath ../..) LC_PROB_NUM=$$ARG "$(CENTRAL_BIN)"; \
	   fi

.SECONDARY:

# Prevent 'run' from being treated as a file target
%:
	@:

# Single problem: build and run with main.go + utils.go + problem.go
NUM ?=
SRC := $(if $(NUM),$(shell ls $(NUM).*\.go 2>/dev/null | head -n1))
BIN := $(if $(NUM),$(BIN_DIR)/lc$(NUM))

.PHONY: build
build: $(BIN_DIR)
ifndef SRC
	$(error No Go file found for NUM='$(NUM)'. Expecting '$(NUM).*\.go')
endif
	$(GO) mod tidy
	$(GO) build -o $(BIN) $(CENTRAL_MAIN) $(UTILS) $(SRC)

LC_STRESS_ITERS ?= 1

.PHONY: fmt vet clean
fmt:
	$(GO) fmt ./...

vet:
	$(GO) vet ./...

clean:
ifneq ($(wildcard $(BIN_DIR)),)
	# Remove all contents (files or directories) inside BIN_DIR safely
	find $(BIN_DIR) -mindepth 1 -maxdepth 1 -exec rm -rf {} +
endif

.PHONY: distclean
distclean: clean
	# Optionally remove the bin directory itself if desired
	rmdir $(BIN_DIR) 2>/dev/null || true

help:
	@echo "LeetCode Go Harness"
	@echo
	@echo "Central runner targets:" 
	@echo "  make run <n|all|category>    # run a problem, all, or category" 
	@echo "  make all                     # alias for run-all" 
	@echo "  make run-all [ITERS=1]       # run all problems" 
	@echo
	@echo "Single problem build modes:" 
	@echo "  make NUM=42 build            # build only central + problem 42" 
	@echo
	@echo "Maintenance:" 
	@echo "  make fmt | vet | clean | distclean" 
	@echo
	@echo "Examples:" 
	@echo "  make run 42" 
	@echo "  make run all" 
	@echo "  make run sliding_window" 
	@echo "  make run two_pointer" 
