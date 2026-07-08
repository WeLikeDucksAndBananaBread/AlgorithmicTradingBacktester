# Algorithmic Trading Backtester

[![Status](https://img.shields.io/badge/status-work_in_progress-yellow.svg)](https://github.com/your-repo/your-project/pulse)

An algorithmic trading backtester written in C++ and Qt that allows you to test and analyze trading strategies against historical market data.

## Features

- **Visual Strategy Builder**: Create complex trading strategies without writing a single line of code.
- **Performance Analytics**: Analyze your strategy's performance with key metrics like Sharpe ratio, max drawdown, and equity curves.
- **Modular Architecture**: Clean, multi-threaded design separating the UI, data handling, and simulation engine.
- **Cross-Platform**: Built with C++ and Qt for compatibility with Windows, macOS, and Linux.

## Project Structure

The project is organized into several distinct modules:

- `src/`: Contains the core back-end logic, divided into:
  - `data`: Data parsing and caching.
  - `logic`: The backtesting engine, event handling, and metrics.
  - `strategy`: The strategy translator and technical indicators.
- `ui/`: The Qt-based user interface, including all windows, widgets, and charts.
- `tests/`: Unit and integration tests for all modules.
- `docs/`: Detailed documentation for each module.

For a comprehensive overview of the architecture and modules, see the [**Modules Overview**](./docs/modules/README.md).

## Build Instructions

### Prerequisites

- C++20 compatible compiler (GCC, Clang, MSVC)
- CMake 4.2+
- Qt 6.x (Core, Gui, Widgets, Test)

### Configuration

If Qt is not in a standard location, set the `Qt6_ROOT` environment variable:

```bash
export Qt6_ROOT=/path/to/Qt/6.x.x/gcc_64
```

### Build Steps

1. **Configure CMake:**

    ```bash
    cmake -S . -B build -G Ninja
    ```

2. **Build the Project:**

    ```bash
    cmake --build build -j 4
    ```

## Usage

### Run the Application

Execute the following command from the project root:

```bash
./build/Algorithmic_Trading_Backtester
```

Or, use the provided CMake target:

```bash
cmake --build build --target run
```

### Run Tests

To run the full suite of unit and integration tests:

```bash
ctest --test-dir build --output-on-failure
```

Or, use the provided CMake target:

```bash
cmake --build build --target run_tests
```
