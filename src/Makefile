dbg:

# Default language: LC_LANG only (cpp|go)
LC_LANG ?= cpp

ifeq ($(LC_LANG),cpp)
LANG_MAKE_DIR := cpp
else ifeq ($(LC_LANG),go)
LANG_MAKE_DIR := go
else
$(error Unknown LC_LANG '$(LC_LANG)'. Supported: cpp, go)
endif

.PHONY: all build run run-all build-all clean help fmt vet submit

all build run run-all build-all clean help fmt vet:
	$(MAKE) -C $(LANG_MAKE_DIR) $@ $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

submit:
	if [ "$(LC_LANG)" = "go" ]; then \
		$(MAKE) -C go submit NUM=$(NUM); \
	else \
		$(MAKE) -C cpp submit NUM=$(NUM); \
	fi

