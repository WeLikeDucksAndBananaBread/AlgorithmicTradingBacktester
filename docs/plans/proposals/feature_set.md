# Algorithmic Trading Backtester - Feature Set

This document outlines the high-level features for the C++/Qt-based Algorithmic Trading Backtester. The project is designed with a minimal but extensible initial feature set to allow a fast development cycle.

## 1. Data Acquisition & Storage

### 1.1 Supported Data Sources
- **Free APIs**: Tiingo, Alpha Vantage, Stooq, Yahoo Finance.
- **Local Files**: Ingestion of local `TXT`/`CSV` files formatted like Stooq downloads.

### 1.2 Data Caching & API Rate Limit Prevention [Discuss later]
- **Manual Data Fetching**: API requests are not made automatically during a backtest. Users must explicitly trigger a "Fetch & Cache" action for a given asset and timeframe.
- **Local Data Storage**: Downloaded data is processed and cached locally (e.g., in SQLite or binary format). 
- **Offline Operations**: All backtesting and charting queries are executed against the local cache, completely avoiding API rate limits during simulations.

### 1.3 Data Parsing
- Usage of `rapidcsv` for robust and quick parsing of CSV data returned by APIs or imported from local files.

## 2. Strategy Module (GUI Builder)

### 2.1 GUI-Based Rule Builder
- **No-Code Strategy Creation**: Users create strategies via an elegant UI without writing C++ code.
- **Condition Chains**: Ability to chain simple technical indicators (e.g., "If SMA 50 crosses above SMA 200") to form entry and exit rules.
- **Parameterization**: Easily adjust strategy parameters (e.g., lookback periods, threshold values) via UI spinboxes and sliders.
- **Extendable Indicator Library**: The underlying engine will support adding new technical indicators that the GUI builder can access.

## 3. Backtesting Engine

### 3.1 Event-Driven Simulation
- The engine simulates the passage of time by feeding historical market data events (Ticks/Bars) to the active strategy.
- **Lookahead Bias Prevention**: Strict separation of historical data visibility; strategies only see data up to the simulated current time.

### 3.2 Order Execution (Initial Phase)
- **Basic Fill Logic**: Initially, the engine supports simple, guaranteed fills (e.g., Fill at Next Open or Fill at Close).
- **Extensibility**: The execution model is structured so that complex mechanics (slippage, partial fills, latency modeling, commission models) can be implemented in later phases.

### 3.3 Metrics & Reporting
- Track core performance metrics: Total Return, Max Drawdown, Sharpe Ratio, Win Rate, and Trade Count.

## 4. Visualization & UI

### 4.1 UI Design
- Built with Qt to provide a responsive, modern desktop application experience.
- The UI is fully decoupled from heavy computations (Data Acquisition and Engine run on separate threads).

### 4.2 Charting with QCustomPlot
- **Market Charts**: High-performance rendering of OHLC candlesticks for historical data.
- **Equity Curves**: Visual tracking of portfolio value over the course of a backtest.
- **Strategy Overlays**: Visual representation of buy/sell signals on top of the price chart.

## 5. Logging
- Integrated `spdlog` for high-performance, structured logging across all threads and modules. Useful for debugging engine state and network requests.
