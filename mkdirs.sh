#!/bin/bash

# Root directories containing problem categories
ROOTS=("array" "linked_list" "sliding_window" "two_pointers")

for ROOT in "${ROOTS[@]}"; do
  # Find all problem directories (directories with a Makefile or solution.cpp)
  find "$ROOT" -mindepth 1 -maxdepth 1 -type d | while read -r PROB_DIR; do
    echo $PROB_DIR
    # Create cpp/ subdirectory if it doesn't exist
    mkdir -p "$PROB_DIR/cpp"
    # Move all C++-related files into cpp/ (adjust patterns as needed)
    mv "$PROB_DIR"/*.cpp "$PROB_DIR"/*.h "$PROB_DIR"/Makefile "$PROB_DIR"/solution* 2>/dev/null "$PROB_DIR/cpp/"
  done
done