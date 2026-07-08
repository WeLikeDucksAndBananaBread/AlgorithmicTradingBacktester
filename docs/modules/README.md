# Algorithmic Trading Backtester - Modules Overview

This document provides a high-level overview of the application's modular architecture. Each module is designed to be a self-contained unit with clear responsibilities.

For a detailed breakdown of the file structure, see [structure_summary.md](./structure_summary.md).

## Core Modules

### 1. Data Acquisition (`src/data/`)
Responsible for parsing historical market data from local files (e.g., CSV) and caching it in memory for efficient access by the backtesting engine.

### 2. Backtesting Engine (`src/logic/`)
The core simulation engine. It runs in a dedicated thread, processing market data event-by-event, executing strategy logic, and tracking portfolio performance.

### 3. Strategy Translator (`src/strategy/`)
Acts as a bridge between the UI and the backtesting engine. It translates the rules and settings from the GUI Strategy Builder into executable C++ strategy objects.

### 4. User Interface (`ui/`)
A Qt-based graphical front-end. It provides the Strategy Builder, configuration windows, performance dashboards, and financial charts. It runs exclusively on the main application thread.

## Threading Model

The application uses a multi-threaded design to keep the UI responsive:

1.  **Main UI Thread**: Handles all user interactions and GUI updates.
2.  **Backtesting Engine Thread**: Runs the core simulation loop, preventing the UI from freezing.
3.  **Data Acquisition Thread**: The architecture supports a dedicated thread for data I/O, which is planned for future implementation.

Cross-thread communication is handled safely using Qt's Signals and Slots mechanism.

## Detailed Module Documentation

More detailed documentation for each module can be found here:
- [Data Acquisition Module](./data_acquisition.md)
- [Backtesting Engine Module](./backtesting_engine.md)
- [Strategy Translator Module](./strategy_translator.md)
- [User Interface Module](./user_interface.md)