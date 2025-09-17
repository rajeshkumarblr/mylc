SHELL := /bin/bash
GO    ?= go

BIN_DIR := ../../build/go
TMP_BUILD_DIR := $(BIN_DIR)/_merged

CATEGORY_DIRS := hash list sliding_window misc two_pointer tree
GO_SRCS := $(sort $(wildcard *.go) $(foreach d,$(CATEGORY_DIRS),$(wildcard $(d)/*.go)))
CENTRAL_MAIN := main.go
UTILS := lc_test_utils.go
CENTRAL_BIN := $(BIN_DIR)/runner

.PHONY: all build build-all fmt vet clean distclean help

DEFAULT_GOAL := help

# Directory targets
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TMP_BUILD_DIR): | $(BIN_DIR)
	mkdir -p $(TMP_BUILD_DIR)

# Build the central runner with all solution files + utils
all: $(TMP_BUILD_DIR)
	@set -euo pipefail; \
	if [ ! -f "$(CENTRAL_MAIN)" ]; then echo "main.go not found"; exit 1; fi; \
	if [ ! -f "$(UTILS)" ]; then echo "lc_test_utils.go not found"; exit 1; fi; \
	cp $(CENTRAL_MAIN) $(UTILS) $(TMP_BUILD_DIR)/; \
	for f in $(filter-out $(CENTRAL_MAIN) $(UTILS),$(GO_SRCS)); do cp $$f $(TMP_BUILD_DIR)/; done; \
	printf 'module tempbuild\n\ngo 1.21\n' > $(TMP_BUILD_DIR)/go.mod; \
	$(GO) -C $(TMP_BUILD_DIR) mod tidy >/dev/null 2>&1 || true; \
	echo "==> Building central runner: $(CENTRAL_BIN)"; \
	$(GO) -C $(TMP_BUILD_DIR) build -o "$(CENTRAL_BIN)" .; \
	echo "Build-all: done."

build: all
build-all: all

fmt:
	$(GO) fmt ./...

vet:
	$(GO) vet ./...

clean:
ifneq ($(wildcard $(BIN_DIR)),)
	find $(BIN_DIR) -mindepth 1 -maxdepth 1 -exec rm -rf {} +
endif

distclean: clean
	rmdir $(BIN_DIR) 2>/dev/null || true

help:
	@echo "LeetCode Go Harness (build-only). Use ./run for execution and submit."
	@echo
	@echo "Targets:"
	@echo "  make / make all / make build     # build central runner -> $(CENTRAL_BIN)"
	@echo "  make clean | distclean           # remove artifacts"
	@echo
	@echo "Run examples (repo root): ./run 42 | ./run -c tree | ./run -a"
	@echo "Submit (repo root): ./run -s 21 -l go  # extract+submit problem 21"
