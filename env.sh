#!/bin/bash

# Set repo root
export REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Default language
export LANG=cpp

# Paths for binaries
export CPP_BIN_DIR="$REPO_ROOT/build/cpp"
export GO_BIN_DIR="$REPO_ROOT/build/go"

# Add repo root to PATH for easy access to scripts like run.sh
export PATH="$REPO_ROOT:$PATH"