# Algorithmic Trading Backtester - System Architecture

This document describes the software architecture, modularization, and threading models for the Algorithmic Trading Backtester. 

## 1. High-Level Technology Stack

- **Core Application Framework**: C++ (std >= C++17) & Qt
- **Network / API Requests**: `QNetworkAccessManager`
- **CSV Parsing**: `rapidcsv`
- **Charting**: `QCustomPlot`
- **Logging**: `spdlog`

## 2. Core Modules

The architecture is strictly modularized to support independent development by different team members.

### 2.1 Data Acquisition Module
Responsible for managing API credentials, constructing HTTP requests to Tiingo, Alpha Vantage, Stooq, and Yahoo Finance, and parsing the responses.
- Handles parsing of local `TXT`/`CSV` files via `rapidcsv`.
- Normalizes data into standard internal `Bar` or `Tick` C++ structs.
- Manages the local caching layer to ensure API limits are avoided.

### 2.2 Backtesting Engine Module
The core state machine that executes simulations.
- Ingests cached historical data.
- Implements the "Basic Fill Logic" (e.g., filling orders at close/open).
- Updates portfolio state, tracks metrics, and maintains trade history.
- Built to be easily extendable for slippage and advanced execution mechanics later.

### 2.3 Strategy Translator Module
Acts as the bridge between the GUI Rule Builder and the Backtesting Engine.
- Parses the configurations created by the user in the UI.
- Translates GUI rules into executable C++ condition objects that the Backtesting Engine can evaluate on each data event.

### 2.4 User Interface & Visualization Module
The Qt-based front-end.
- Contains the GUI Strategy Builder.
- Renders `QCustomPlot` instances for candlesticks and equity curves.
- Displays metrics tables.

## 3. Threading Model

To ensure a highly responsive UI, the application distributes workloads across distinct threads:

1. **Main UI Thread**: Handles all Qt widget painting, user interactions, and `QCustomPlot` rendering.
2. **Data Acquisition Thread (Worker)**: Performs blocking operations like reading large CSV files from disk, writing to the local cache, and executing network requests.
3. **Backtesting Engine Thread (Worker)**: Runs the tight simulation loop, processing data events and executing strategy logic.

## 4. Event-Driven Architecture (Cross-Thread Communication)

The architecture utilizes **Qt's Native Signals and Slots mechanism** for all cross-thread communication. 

### 4.1 Why Qt Signals and Slots?
- **Safety**: Qt handles thread-safe queuing of arguments automatically when signals are emitted across thread boundaries (Queued Connection).
- **Development Velocity**: Shorter implementation time compared to rolling a custom thread-safe event bus using `std::queue`, mutexes, and condition variables.
- **Bug Prevention**: Reduces the risk of deadlocks and race conditions.

### 4.2 Event Flow Example
1. **User Action**: User clicks "Run Backtest" in the UI (Main Thread).
2. **Signal Emitted**: UI emits `startSimulation(strategyConfig, datasetId)`.
3. **Slot Triggered**: Engine Thread receives the configuration, loads the locally cached data, and begins the loop.
4. **Engine Updates**: As the simulation progresses, the Engine Thread emits signals like `simulationProgress(int percentage)` and `tradeExecuted(TradeDetails trade)`.
5. **UI Responds**: The UI Thread receives these signals and safely updates the progress bar and chart without locking.
