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
CENTRAL_BIN := $(BIN_DIR)/runall

# Build the central runner with all solution files + utils
.PHONY: build-all
build-all: $(BIN_DIR)
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
run-all: build-all
	@echo "==> Running all problems via central runner"
	LC_STRESS_ITERS=$(ITERS) "$(CENTRAL_BIN)"

.DEFAULT_GOAL := run

.PHONY: run
run:
	@if [ "$(firstword $(MAKECMDGOALS))" = "run" ]; then \
		ARG=$(word 2,$(MAKECMDGOALS)); \
		if [ -z "$$ARG" ]; then \
			echo "Usage: make run <problem_no|all>"; exit 1; \
		fi; \
		$(MAKE) build-all; \
		if [ "$$ARG" = "all" ]; then \
			echo "==> Running all problems via central runner"; \
			"$(CENTRAL_BIN)"; \
		else \
			echo "==> Running problem $$ARG via central runner"; \
			LC_PROB_NUM=$$ARG "$(CENTRAL_BIN)"; \
		fi; \
		exit 0; \
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
	rm -f $(BIN_DIR)/*
endif

help:
	@echo "Usage:"
	@echo "  make run-all ITERS=1       # run all problems (summary, via central runner)"
	@echo "  make build-all             # build central runner"
	@echo "  make <num>                 # build & run e.g., 42"
	@echo "  make run NUM=42            # build & run"
	@echo "  make fmt | vet | clean"
