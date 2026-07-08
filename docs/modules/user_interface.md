# User Interface & Visualization Module

## Overview

The User Interface (UI) module is the Qt-based front-end for the application. It provides all visual components for user interaction, including strategy creation, backtest configuration, and results visualization.

## Location

- **Source Code**: `ui/`
- **Headers**: `ui/`

## Responsibilities

- Providing a GUI Strategy Builder for no-code strategy creation.
- Rendering financial charts (candlesticks, equity curves) using QCustomPlot.
- Displaying performance metrics and trade history in a user-friendly dashboard.
- Managing the overall application workflow and user interactions.

## Components

- `MainWindow` - The main application window.
- `/strategy_builder` - The visual interface for creating trading strategies.
- `/charts` - Charting components for market data and equity curves.
- `/dashboard` - Widgets for displaying performance metrics.
- `/settings` - Configuration and preferences management UI.
- `/widgets` - Reusable custom Qt widgets used throughout the application.

## Threading

This module operates **exclusively** on the main UI thread. All updates from other threads (like the backtesting engine) are handled asynchronously and safely via Qt's Signals and Slots mechanism.
