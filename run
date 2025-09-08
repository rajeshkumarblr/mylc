#!/bin/bash

# Source environment
source "$(dirname "$0")/env.sh"

if [ $# -lt 1 ]; then
    echo "Usage: $0 <problem_number> [lang]"
    exit 1
fi

PROBLEM="$1"
LANG_ARG="${2:-$LC_LANG}"

if [ "$LANG_ARG" = "cpp" ]; then
    BIN="$CPP_BIN_DIR/lc${PROBLEM}"
    SRC_DIR="$REPO_ROOT/src/cpp"
    # Find the source file in all category dirs
    SRC_FILE=$(find "$SRC_DIR" -name "lc${PROBLEM}.cpp" | head -n 1)
    if [ ! -f "$BIN" ]; then
        if [ -z "$SRC_FILE" ]; then
            echo "Source file not found for problem $PROBLEM in C++"
            exit 2
        fi
        echo "Building $SRC_FILE..."
        make -C "$(dirname "$SRC_FILE")" "lc${PROBLEM}" || exit 3
    fi
elif [ "$LANG_ARG" = "go" ]; then
    BIN="$GO_BIN_DIR/lc${PROBLEM}"
    SRC_DIR="$REPO_ROOT/src/go"
    SRC_FILE=$(find "$SRC_DIR" -name "lc${PROBLEM}.go" | head -n 1)
    if [ ! -f "$BIN" ]; then
        if [ -z "$SRC_FILE" ]; then
            echo "Source file not found for problem $PROBLEM in Go"
            exit 2
        fi
        echo "Building $SRC_FILE..."
        go build -o "$BIN" "$SRC_FILE" || exit 3
    fi
elif [ "$LANG_ARG" = "python" ]; then
    SRC_FILE=$(find "$REPO_ROOT/src/python" -name "lc${PROBLEM}.py" | head -n 1)
    if [ -z "$SRC_FILE" ]; then
        echo "Source file not found for problem $PROBLEM in Python"
        exit 2
    fi
    BIN="$SRC_FILE"
else
    echo "Unsupported language: $LANG_ARG"
    exit 4
fi

if [ ! -x "$BIN" ]; then
    echo "Binary not found or not executable: $BIN"
    exit 5
fi

echo "Running $LANG_ARG solution for problem $PROBLEM:"
if [ "$LANG_ARG" = "python" ]; then
    python3 "$BIN"
else
    "$BIN"
fi