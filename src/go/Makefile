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

# Detect if first goal is a problem number (e.g., 42)
GOALS := $(filter-out help,$(MAKECMDGOALS))
PROB  := $(firstword $(GOALS))
KNOWN := help build run stress dbg race clean fmt vet build-all run-all list print-%
ifneq ($(filter $(PROB),$(KNOWN)),)
  NUM :=
else
  NUM := $(PROB)
endif

# From NUM → source/binary (e.g., 42.*.go → build/go/lc42)
SRC := $(if $(NUM),$(shell ls $(NUM).*\.go 2>/dev/null | head -n1))
BIN := $(if $(NUM),$(BIN_DIR)/lc$(NUM))

# Discover all go files in this flat dir
GO_SRCS := $(sort $(wildcard *.go))

# Flags
RACE_FLAG :=
ifeq ($(RACE),1)
  RACE_FLAG := -race
endif

.PHONY: all help
all:
	@:

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# ---------- Single problem ----------
.PHONY: build
build: $(BIN_DIR)
ifndef SRC
	$(error No Go file found for NUM='$(NUM)'. Expecting '$(NUM).*\.go')
endif
	$(GO) mod tidy
	$(GO) build $(RACE_FLAG) -o $(BIN) $(SRC)

LC_STRESS_ITERS ?= 1

.PHONY: run
run:
ifeq ($(NUM),)
	@$(MAKE) run-all
else ifeq ($(NUM),all)
	@$(MAKE) run-all
else
	$(MAKE) build NUM=$(NUM)
	LC_STRESS_ITERS=$(LC_STRESS_ITERS) $(BIN)
endif

# Default N for "stress" only
N ?= 100
.PHONY: stress
stress: build
	LC_STRESS_ITERS=$(N) $(BIN)

# Build with no inlining/opts & run under Delve
.PHONY: dbg
dbg: $(BIN_DIR)
ifndef SRC
	$(error No Go file found for NUM='$(NUM)'.)
endif
	$(GO) build -gcflags "all=-N -l" -o $(BIN) $(SRC)
	LC_STRESS_ITERS ?= 1
	$(DLV) exec -- $(BIN)

# Handy wrapper: run with -race
.PHONY: race
race:
	@$(MAKE) -s run NUM=$(NUM) RACE=1

# ---------- All problems ----------
.PHONY: build-all
build-all: $(BIN_DIR)
	@set -euo pipefail; \
	if [ -z "$(GO_SRCS)" ]; then echo "No *.go files found"; exit 1; fi; \
	$(GO) mod tidy; \
	for f in $(GO_SRCS); do \
	  num="$${f%%.*}"; \
	  bin="$(BIN_DIR)/lc$${num}"; \
	  echo "==> Building $$f  ->  $$bin"; \
	  $(GO) build $(RACE_FLAG) -o "$$bin" "$$f"; \
	done
	@echo "Build-all: done."

# ITERS controls LC_STRESS_ITERS for run-all (default 1)
ITERS ?= 1
.PHONY: run-all
run-all: build-all
	@set -euo pipefail; \
	pass=0; fail=0; total=0; \
	for f in $(GO_SRCS); do \
	  num="$${f%%.*}"; \
	  bin="$(BIN_DIR)/lc$${num}"; \
	  echo "==> Running $$bin"; \
	  if LC_STRESS_ITERS=$(ITERS) "$$bin"; then \
	    pass=$$((pass+1)); \
	  else \
	    fail=$$((fail+1)); \
	  fi; \
	  total=$$((total+1)); \
	done; \
	echo ""; \
	echo "Summary: $$pass passed, $$fail failed, $$total total"; \
	[ $$fail -eq 0 ]

.PHONY: list
list:
	@for f in $(GO_SRCS); do echo $${f%%.*}; done

# ---------- Hygiene ----------
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
	@echo "  make <num>                 # build & run e.g., 42"
	@echo "  make run NUM=42            # build & run"
	@echo "  make stress NUM=42 N=1e5   # stress one problem"
	@echo "  make dbg NUM=42            # build (no inline) + run under Delve"
	@echo "  make race NUM=42           # run with -race"
	@echo "  make build-all             # build all problems"
	@echo "  make run-all ITERS=1       # run all problems (summary)"
	@echo "  make fmt | vet | clean | list"

# Allow 'make 42' to dispatch to run
ifneq ($(NUM),)
.PHONY: $(NUM)
$(NUM):
	@$(MAKE) -s run NUM=$(NUM)
endif

print-%:
	@echo $*=$($*)
