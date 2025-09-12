C++ Central Test Harness
========================

- `main.cpp` parses `testcases.json` and dispatches to per-problem runners.
- It looks for `testcases.json` in these locations (in order):
  1. `./testcases.json`
  2. `src/cpp/testcases.json`
  3. `src/go/testcases.json`  ← current location in this repo

Build & Run
-----------
```
cd src/cpp
make build-all
make run-all
make 42            # run a single problem: NUM=42
make run NUM=1
```
Notes
-----
- Existing problem .cpp files still contain their own standalone `main()` blocks,
  but they're compiled with `-DLC_STANDALONE_MAIN=0` under the central runner,
  so those local mains are disabled.
- If you want to compile a single problem as a self-contained program, you can do
  so manually with: `g++ -std=gnu++20 -DLC_STANDALONE_MAIN=1 42.trapping-rain-water.cpp -o lc42`
