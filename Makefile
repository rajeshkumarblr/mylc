# Minimal Makefile to submit LeetCode problems via Python helper
PY ?= python3
SUBMIT_PY := scripts/submit_lc.py
LC_LANG ?= cpp

RAW := $(MAKECMDGOALS)
ID  ?= $(word 2,$(RAW))

.PHONY: submit
submit:
	@if [ -z "$(ID)" ]; then echo "Usage: make submit <id> [LC_LANG=cpp|go]"; exit 2; fi; \
	$(PY) $(SUBMIT_PY) --id $(ID) --lang $(LC_LANG)

# Prevent GNU Make from treating the numeric id as a target
%:
	@:
