SHELL := /bin/bash

BIN_DIR := ../../build/python
RUNNER := $(BIN_DIR)/runner

.PHONY: all build clean distclean help

all: $(RUNNER)

$(RUNNER):
	@mkdir -p $(BIN_DIR)
	@echo "==> Creating runner: $(RUNNER)";
	@echo '#!/usr/bin/env bash' > $(RUNNER)
	@echo 'set -Eeuo pipefail' >> $(RUNNER)
	@echo 'DIR="$$(cd "$$(dirname "$$0")" && pwd)"' >> $(RUNNER)
	@echo 'REPO_ROOT="$$(git rev-parse --show-toplevel 2>/dev/null || pwd)"' >> $(RUNNER)
	@echo 'export PYTHONPATH="$$REPO_ROOT/src/python:$${PYTHONPATH:-}"' >> $(RUNNER)
	@echo 'exec python3 "$$REPO_ROOT/src/python/main.py"' >> $(RUNNER)
	@chmod +x $(RUNNER)
	@echo "Build: done."

build: all

clean:
	@if [ -d "$(BIN_DIR)" ]; then find "$(BIN_DIR)" -mindepth 1 -maxdepth 1 -exec rm -rf {} +; fi

distclean: clean
	rmdir $(BIN_DIR) 2>/dev/null || true

help:
	@echo "LeetCode Python Harness (runner setup). Use ./run for execution."
	@echo "Targets: make | make all | make build | make clean"
