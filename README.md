## Status: Work in Progress
# AlgorithmicTradingBacktester
Algorithmic Trading Backtester written in C++ which allows you to review how your securities would have performed if you had followed different trading strategies.

## Structure

- `src/` — application entry point and core logic
- `ui/` — Qt UI widgets and windows
- `tests/` — standalone test executables

## Build

If Qt is not installed in a standard location, point CMake to it with `Qt6_ROOT`:

```bash
export Qt6_ROOT=/path/to/Qt/6.11.1/gcc_64
```

Then configure and build:

```bash
cmake -S . -B cmake-build-debug -G Ninja
cmake --build cmake-build-debug -j 4
```

You can also pass it directly to CMake:

```bash
cmake -S . -B cmake-build-debug -G Ninja -DQt6_ROOT=/path/to/Qt/6.11.1/gcc_64
```

## Run tests

```bash
ctest --test-dir cmake-build-debug --output-on-failure
```

## Run the app

```bash
./cmake-build-debug/Algorithmic_Trading_Backtester
```
## Documentation
[Architecture Plan](./docs/plan/ARCHITECTUREPLAN.md)

