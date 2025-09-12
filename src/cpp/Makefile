%:
	@:
run.%:
	@$(MAKE) run $(subst run.,,$@)
SHELL := /bin/bash

CXX ?= g++
CXXFLAGS ?= -std=gnu++20 -O2 -pipe -Wall -Wextra -Wno-unused-parameter -I. -DLC_LOCAL_TEST
LDFLAGS ?=


SHELL := /bin/bash
CXX ?= g++
CXXFLAGS ?= -std=gnu++20 -O2 -pipe -Wall -Wextra -Wno-unused-parameter -I. -DLC_LOCAL_TEST
LDFLAGS ?=

ROOT := $(abspath $(CURDIR)/../..)
SRC_DIR := $(CURDIR)
BIN_DIR := $(ROOT)/build/cpp
CENTRAL := $(BIN_DIR)/lc_all

PROBLEM_SRCS := $(filter-out $(SRC_DIR)/main.cpp, $(wildcard $(SRC_DIR)/*.cpp))
PROBLEM_OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(PROBLEM_SRCS))


.PHONY: all build run build-all clean submit help
.NOTPARALLEL:

all: build

build: $(CENTRAL)

run: build

$(BIN_DIR):
	mkdir -p $(BIN_DIR)


$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(SRC_DIR)/lc_test_utils.h | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(CENTRAL): $(BIN_DIR)/main.o $(PROBLEM_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

ID := $(word 2,$(MAKECMDGOALS))

run:
ifeq ($(ID),all)
	$(MAKE) $(CENTRAL)
	REPO_ROOT=$(ROOT) NUM=all $(CENTRAL)
else ifneq ($(ID),)
	CATEGORIES="two_pointer sliding_window hash list misc tree"; \
	if echo "$$CATEGORIES" | grep -wq "$(ID)"; then \
		$(MAKE) $(CENTRAL); \
		REPO_ROOT=$(ROOT) LC_CATEGORY=$(ID) $(CENTRAL); \
	else \
		src=""; obj=""; \
		for f in $(PROBLEM_SRCS); do \
		  base=$$(basename $$f); id=$${base%%.*}; \
		  if [ "$$id" = "$(ID)" ]; then src="$$f"; obj="$(BIN_DIR)/$${base%.cpp}.o"; fi; \
		done; \
		if [ -z "$$obj" ]; then echo "No source for problem $(ID) in $(SRC_DIR)"; exit 3; fi; \
		$(MAKE) $(BIN_DIR)/main.o $(PROBLEM_OBJS); \
		$(CXX) $(CXXFLAGS) -o $(CENTRAL) $(BIN_DIR)/main.o $(PROBLEM_OBJS) $(LDFLAGS); \
		REPO_ROOT=$(ROOT) NUM=$(ID) $(CENTRAL); \
	fi
else
	@echo "Usage: make run <id|all|category>"; exit 1
endif

run-all:
	$(MAKE) $(CENTRAL)
	REPO_ROOT=$(ROOT) NUM=all $(CENTRAL)

build-all: $(CENTRAL)
	@echo "Built $(CENTRAL)"

submit:
	@if [ -z "$(NUM)" ]; then echo "Usage: make submit NUM=<id>"; exit 2; fi; \
	src=""; \
	for f in $(PROBLEM_SRCS); do \
	  base=$$(basename $$f); id=$${base%%.*}; \
	  if [ "$$id" = "$(NUM)" ]; then src="$$f"; fi; \
	done; \
	if [ -z "$$src" ]; then echo "No source for problem $(NUM)"; exit 3; fi; \
	out="$(BIN_DIR)/submit.$(NUM).cpp"; \
	mkdir -p "$(BIN_DIR)"; \
	awk '/@lc code=start/{flag=1; print; next} /@lc code=end/{print; flag=0} flag' "$$src" > "$$out"; \
	echo "Wrote $$out (exact @lc code block)."

clean:
	rm -rf $(BIN_DIR)

help:
	@echo "Usage:"
	@echo "  make run 1         # build & run a single problem"
	@echo "  make run all       # build & run all problems"
	@echo "  make run list      # build & run all problems in 'list' category"
	@echo "  make run tree      # build & run all problems in 'tree' category"
	@echo "  make run <category> # build & run all problems in category"
	@echo "  make submit NUM=1  # extract @lc code block -> build/cpp/submit.1.cpp"
	mkdir -p "$(BIN_DIR)"; \
