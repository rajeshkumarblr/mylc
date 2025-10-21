SHELL := /bin/bash

JAVAC ?= javac
JAVA  ?= java

BIN_DIR := ../../build/java
CLASSES_DIR := $(BIN_DIR)/bin
RUNNER := $(BIN_DIR)/runner
LIB_DIR := lib
LIBS := $(LIB_DIR)/gson-2.10.1.jar

SRC_ROOT := .
SRC_DIRS := . hash list misc sliding_window two_pointer tree stack binary_search prefix_sum graphs
JAVA_SRCS := $(sort $(wildcard *.java) $(foreach d,$(SRC_DIRS),$(wildcard $(d)/*.java)))

.PHONY: all build clean distclean help

all: $(RUNNER)

$(CLASSES_DIR):
	@mkdir -p $(CLASSES_DIR)

$(RUNNER): $(CLASSES_DIR)
	@echo "==> Compiling Java sources to $(CLASSES_DIR)";
	@$(JAVAC) -g -cp $(LIBS) -d $(CLASSES_DIR) $(JAVA_SRCS)
	@mkdir -p $(BIN_DIR)
	@# Copy libs to build dir for runtime
	@mkdir -p $(BIN_DIR)/lib
	@for f in $(LIBS); do cp -f $$f $(BIN_DIR)/lib/; done
	@echo "==> Creating runner: $(RUNNER)";
	@echo '#!/usr/bin/env bash' > $(RUNNER)
	@echo 'set -Eeuo pipefail' >> $(RUNNER)
	@echo 'DIR="$$(cd "$$(dirname "$$0")" && pwd)"' >> $(RUNNER)
	@echo 'exec java -cp "$$DIR/bin:$$DIR/lib/gson-2.10.1.jar" Main' >> $(RUNNER)
	@chmod +x $(RUNNER)
	@echo "Build: done."

build: all

clean:
	@if [ -d "$(BIN_DIR)" ]; then find "$(BIN_DIR)" -mindepth 1 -maxdepth 1 -exec rm -rf {} +; fi

distclean: clean
	rmdir $(BIN_DIR) 2>/dev/null || true

help:
	@echo "LeetCode Java Harness (build-only). Use ./run for execution."
	@echo "Targets: make | make all | make build | make clean"
