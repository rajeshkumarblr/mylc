# Flat-structure Go harness mirroring your C++ flow.
# Examples:
#   make 42                 # build & run 42.trapping-rain-water.go
#   make run NUM=42         # build & run explicitly
#   make stress NUM=42 N=1e5
#   make clean              # remove built binaries

SHELL := /bin/bash
GO ?= go
BIN_DIR := ../../build/go

# Detect if the first goal looks like a problem number (e.g., 42).
PROB_NUM := $(firstword $(MAKECMDGOALS))
KNOWN := help build run stress clean fmt vet
ifneq ($(filter $(PROB_NUM),$(KNOWN)),)
  NUM :=
else
  NUM := $(PROB_NUM)
endif

# Derive source/binary from NUM when provided
SRC := $(if $(NUM),$(shell ls $(NUM).*\.go 2>/dev/null),)
BIN := $(if $(NUM),$(BIN_DIR)/lc$(NUM),)

.PHONY: all help build run stress clean fmt vet

all: help

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

build: $(BIN_DIR)
ifndef SRC
	$(error Provide a problem number, e.g. 'make 42', or ensure '$(NUM).*\.go' exists)
endif
	$(GO) mod tidy
	$(GO) build -o $(BIN) $(SRC)

run: build
	LC_STRESS_ITERS ?= 1
	LC_STRESS_ITERS=$(LC_STRESS_ITERS) $(BIN)

N ?= 100
stress: build
	LC_STRESS_ITERS=$(N) $(BIN)

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
	@echo "  make <num>          # build & run e.g., make 42"
	@echo "  make run NUM=42     # build & run"
	@echo "  make stress NUM=42 N=100000"
	@echo "  make fmt|vet|clean"

# If invoked like 'make 42', dispatch to run NUM=42
ifneq ($(NUM),)
.PHONY: $(NUM)
$(NUM):
	@$(MAKE) -s run NUM=$(NUM)
endif
