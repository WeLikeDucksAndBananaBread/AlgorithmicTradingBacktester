# Backtesting Engine Module

## Overview

The Backtesting Engine is the heart of the application. It is responsible for simulating trading strategies against historical data and generating performance results.

## Location

- **Source Code**: `src/logic/`
- **Headers**: `src/logic/`

## Responsibilities

- Executing a time-driven simulation loop based on the provided market data.
- Handling events for market data updates, buy/sell signals, and order fills.
- Implementing fill logic (e.g., executing orders at the next bar's open price).
- Tracking portfolio state, including cash, positions, and overall equity.
- Calculating and reporting key performance metrics (e.g., Sharpe ratio, max drawdown).

## Components

- `/engine` - Contains the core `BacktestEngine` and `SimulationLoop`.
- `/events` - Defines the event handling system for the simulation.
- `/metrics` - Includes modules for calculating `PerformanceMetrics`.
- `/strategies` - Contains the `StrategyBase` interface that all trading strategies must implement.

## Threading

The engine runs in a dedicated **Backtesting Engine Thread** to ensure the UI remains responsive during complex and time-consuming simulations. It communicates with the UI and other modules asynchronously via Qt's Signals and Slots.
