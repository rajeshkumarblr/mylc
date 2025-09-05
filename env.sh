#!/bin/bash

# Set repo root
export REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Default language
export LC_LANG=cpp

# Paths for binaries
export CPP_BIN_DIR="$REPO_ROOT/build/cpp"
export GO_BIN_DIR="$REPO_ROOT/build/go"
export PY_BIN_DIR="$REPO_ROOT/build/python"

# Add repo root to PATH for easy access to scripts like run.sh
export PATH="$REPO_ROOT:$PATH"

# Solution symlink
export SOLUTION="$REPO_ROOT/solution"

# ---- Perf setup ----
# Use fixed perf binary shipped with linux-tools
export PERF_BIN="/usr/lib/linux-tools-6.8.0-79/perf"
# Prepend its directory to PATH so 'perf' just works
export PATH="$(dirname "$PERF_BIN"):$PATH"
