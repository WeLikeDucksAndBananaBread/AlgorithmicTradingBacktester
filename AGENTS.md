# Agent Contributing Guide

This guide is for AI agents working on this project. It provides instructions on how to build, test, and contribute to this repository.

## 1. Project Overview

This is a C++ application for backtesting algorithmic trading strategies. It uses Qt for the user interface. The project is divided into several modules:

-   `src/data`: Data parsing and caching.
-   `src/logic`: The backtesting engine.
-   `src/strategy`: Strategy translation and technical indicators.
-   `ui/`: The Qt-based user interface.

For more details, see `docs/modules/README.md`.

## 2. Development Setup

### Dependencies

-   C++20 compiler
-   CMake 4.2+
-   Qt 6.x

### Build

To configure and build the project, run the following commands from the root directory:

```bash
# Configure
cmake -S . -B build -G Ninja

# Build
cmake --build build
```

The build process will automatically run `clang-tidy` to check for code quality issues.

### Run

To run the main application:

```bash
cmake --build build --target run
```

## 3. Testing

To run all tests, use the `run_tests` target:

```bash
cmake --build build --target run_tests
```

## 4. Coding Style

This project uses `clang-format` with the Google C++ style. Please format any changed code before committing. A `.clang-format` file is provided in the root directory.

## 5. Creating New Components

When adding new components, please follow the existing structure. Templates for common components can be found in `docs/templates/`.

For example, to create a new indicator:
1.  Copy `docs/templates/IndicatorTemplate.h` and `IndicatorTemplate.cpp` to `src/strategy/indicators/`.
2.  Rename the files and the class to match the new indicator.
3.  Implement the calculation logic in the `.cpp` file.
4.  Add the new files to the `backtester_strategy` library in `CMakeLists.txt`.
