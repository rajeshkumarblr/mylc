SHELL := /bin/bash

# Supported languages and their Makefile paths
LANG_MAKEFILES := src/cpp/Makefile src/go/Makefile

# Default language
LC_LANG ?= cpp

# Helper to get Makefile path

ifeq ($(LC_LANG),cpp)
LANG_MAKE_DIR := src/cpp
else ifeq ($(LC_LANG),go)
LANG_MAKE_DIR := src/go
else
$(error Unknown LC_LANG '$(LC_LANG)'. Supported: cpp, go)
endif
ifeq ($(origin LC_LANG), undefined)
LC_LANG := cpp
endif

# Delegate all targets except 'submit' to language-specific Makefile
.PHONY: all build run run-all build-all clean help fmt vet


# Forward arguments for run/run-all/build-all
all build run run-all build-all clean help fmt vet:
	$(MAKE) -C $(LANG_MAKE_DIR) $@ $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

# Special handling for submit: only handled at top level
# Minimal Makefile to submit LeetCode problems via Python helper
PY ?= python3
SUBMIT_PY := scripts/submit_lc.py
LC_LANG ?= cpp

RAW := $(MAKECMDGOALS)
ID  ?= $(word 2,$(RAW))

.PHONY: submit
submit:
	@echo "Top-level submit: usage make submit <id> [LC_LANG=cpp|go]"
	if [ "$(LC_LANG)" = "go" ]; then \
		$(MAKE) -C src/go submit NUM=$(ID); \
	else \
		$(MAKE) -C src/cpp submit NUM=$(ID); \
	fi

# Prevent GNU Make from treating the numeric id as a target
%:
	@:
