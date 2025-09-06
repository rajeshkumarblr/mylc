#!/usr/bin/env bash

# Resolve repo root (bash)
export REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Defaults
export LC_LANG=cpp
export BUILD_DIR="$REPO_ROOT/build"
export CPP_BIN_DIR="$BUILD_DIR/cpp"
export GO_BIN_DIR="$BUILD_DIR/go"
export PY_BIN_DIR="$BUILD_DIR/python"

# Helper: prepend dir to PATH if it exists and isn't already in PATH
path_prepend() {
  [ -d "$1" ] || return 0
  case ":$PATH:" in
    *":$1:"*) : ;;
    *) export PATH="$1:$PATH" ;;
  esac
}

# Put our bins on PATH so `lc94` etc. just work
path_prepend "$CPP_BIN_DIR"
path_prepend "$GO_BIN_DIR"
path_prepend "$PY_BIN_DIR"

# Also add repo root so scripts in top-level are callable
path_prepend "$REPO_ROOT"

# ---- Perf setup ----
export PERF_BIN="/usr/lib/linux-tools-6.8.0-79/perf"
path_prepend "$(dirname "$PERF_BIN")"
