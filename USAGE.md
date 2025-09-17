# Build & Test Guide (C++ and Go)

This repo contains C++ and Go solutions executed via central runners and a shared test harness driven by `testcases.json`. Use the `run` helper for day-to-day work; Makefiles are build-only.

- Single env var for language: `LC_LANG` (cpp|go)
- Problem selection via `-p` or env `LC_PROB_NUM`/`LC_PROB_NO`
- Category selection via `-c` or env `LC_CATEGORY`

## Layout
```
./
  run            # helper to build runners on demand and execute
  testcases.json # problems & test cases (single source of truth)
  src/
    cpp/         # C++ sources + Makefile (build-only)
    go/          # Go sources + Makefile (build-only)
  build/
    cpp/runner   # C++ central runner (auto-built)
    go/runner    # Go central runner (auto-built)
```

## Quickstart
- Set default language (optional):
  ```bash
  export LC_LANG=cpp   # or: go
  ```
- Run single problem:
  ```bash
  ./run -p 94
  ./run -l go -p 567
  ```
- Run category / all:
  ```bash
  ./run -c tree
  ./run -a
  ```
- List problems/categories:
  ```bash
  ./run -l
  ./run -L
  ```

## `run` helper
- Builds language runner if missing (`make -C src/<lang> all`)
- Validates problem exists (for `-p`) and implementation exists for chosen language
- Exports `LC_PROB_NUM`/`LC_CATEGORY` for the runner

Flags:
- `-l, --lang [cpp|go]` choose language (default from `$LC_LANG`, else `cpp`); without argument lists problems/categories
- `-p, --problem [id]` run a single problem; if omitted, uses `$LC_PROB_NUM` or `$LC_PROB_NO`
- `-c, --category [cat]` run a category; if omitted, uses `$LC_CATEGORY`
- `-a, --all` run all problems
- `-s, --submit <id>` submit code via `vsc-leetcode-cli` (language from `-l` or `$LC_LANG`)

## C++ build (src/cpp)
- `make` or `make all` builds the optimized runner at `build/cpp/runner`
- `make dbg` builds a debug binary `build/cpp/runner.dbg`
- `make clean` removes artifacts

The Makefile compiles:
- `main.cpp` (driver), `lc_test_utils.*` (shared utils)
- Per-problem sources under category folders

## Go build (src/go)
- `make` or `make all` builds the runner at `build/go/runner`
- `make fmt` formats sources; `make vet` runs static checks
- `make clean` removes artifacts; `make distclean` removes dir if empty

Build strategy:
- Sources are copied to `build/go/_merged` with a temp module to build a single binary

## Environment variables
- `LC_LANG`: default language for run (cpp|go)
- `LC_PROB_NUM` / `LC_PROB_NO`: single problem id when using `./run -p` without an argument
- `LC_CATEGORY`: category for `./run -c` without an argument
- `LC_VERBOSE`: reserved for future per-test verbosity

Runners also rely on:
- `REPO_ROOT`: auto-set to locate `testcases.json`

## VS Code
- `.vscode/launch.json` provides C++ and Go debug configs using the built runners; set `LC_LANG` and `LC_PROB_NUM` as needed.

## Troubleshooting
- Runner missing: first invocation will auto-build; otherwise run `make -C src/<lang> clean all`
- Problem not found: ensure id exists in `testcases.json` and is implemented in `src/<lang>/<category>/<id>.*`
- Go build module errors: `make -C src/go clean` then rebuild (clears `_merged`)

## Development workflow
Use the smoke test to validate changes to Makefiles or the run script:
```bash
./test.sh
```
It cleans/builds runners, lists problems, and runs all/category/single for both languages (skips Go if toolchain missing).
