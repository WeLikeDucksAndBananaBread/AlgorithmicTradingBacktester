# Algorithmic Trading Backtester - Module Structure

This document outlines the implemented module structure, which is based on the architecture defined in the `docs/plans/` directory.

## Directory Structure

```
├── src/
│   ├── core/                     # Core application components (AppInfo)
│   ├── data/                     # Data Acquisition Module
│   │   ├── api/                  # (Future) API client implementations
│   │   ├── cache/                # Local data caching (DataCache)
│   │   ├── models/               # Data structures (Bar, Tick)
│   │   └── parsers/              # Data parsers (CSV, JSON)
│   ├── logic/                    # Backtesting Engine Module
│   │   ├── engine/               # Core simulation engine
│   │   ├── events/               # Event handling system
│   │   ├── metrics/              # Performance metrics calculation
│   │   └── strategies/           # Base strategy interface
│   └── strategy/                 # Strategy Translator Module
│       ├── conditions/           # Base condition interface
│       ├── indicators/           # Technical indicators (SMA, EMA)
│       ├── parser/               # GUI rule parser
│       └── translator/           # Rule-to-code translator
├── ui/                       # User Interface & Visualization Module
│   ├── MainWindow.*          # Main application window
│   ├── charts/               # Charting components
│   ├── dashboard/            # Performance dashboard
│   ├── settings/             # Application settings
│   ├── strategy_builder/     # GUI Strategy Builder
│   └── widgets/              # Custom widgets
└── main.cpp                  # Application entry point
```

## Module Responsibilities

### 1. Data Acquisition Module (`src/data/`)

- Parses historical data from local files (CSV, JSON).
- Implements local data storage (in-memory cache) to optimize access.
- Provides standardized data structures (`Bar`, `Tick`) to other modules.
- *Note: Direct API connections for live data are planned for a future release.*

### 2. Backtesting Engine Module (`src/logic/`)

- Executes the core trading simulation loop in a dedicated thread.
- Implements event-driven architecture for handling market data and trade signals.
- Tracks portfolio state, including positions and equity.
- Calculates key performance metrics (e.g., Sharpe ratio, drawdown).

### 3. Strategy Translator Module (`src/strategy/`)

- Parses trading rules defined by the user in the GUI.
- Translates these rules into executable C++ condition and indicator objects.
- Supports a library of technical indicators (e.g., SMA, EMA).
- Creates thread-safe strategy objects for the backtesting engine.

### 4. User Interface & Visualization Module (`ui/`)

- Provides a Qt-based front-end for strategy building and backtest configuration.
- Renders financial charts (candlesticks, equity curves).
- Displays performance metrics and trade history in a dashboard.
- Operates exclusively on the main UI thread.

## Threading & Communication

- **Main UI Thread**: Manages all user interactions and GUI updates.
- **Backtesting Engine Thread**: Runs the simulation loop to prevent UI freezing.
- **Communication**: Cross-thread communication is handled safely using Qt's Signals and Slots mechanism.

## Technologies Used

- **Core Language**: C++20
- **UI Framework**: Qt 6
- **Charting**: QCustomPlot (integrated into the UI)
- **Build System**: CMake
- **Testing**: QTest (via CTest)
