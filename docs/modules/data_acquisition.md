# Data Acquisition Module

## Overview

The Data Acquisition Module is responsible for sourcing, parsing, and caching market data for the backtesting engine.

## Location

- **Source Code**: `src/data/`
- **Headers**: `src/data/`

## Responsibilities

- Parsing historical market data from local files (e.g., CSV, JSON).
- Caching data in memory to provide fast, repeated access during simulations.
- Providing clean, standardized data structures (`Bar`, `Tick`) for the rest of the application.

*Note: In its current implementation, this module reads data from local files. Direct connections to live data APIs are planned for a future release.*

## Components

- `/parsers` - Contains parsers for different data formats (e.g., `csv_parser`, `json_parser`).
- `/cache` - Manages the in-memory `DataCache` for storing and retrieving datasets.
- `/models` - Defines the core data structures for financial data, such as `Bar` (OHLCV) and `Tick`.
- `/api` - A placeholder for future API client implementations.

## Threading

This module is designed to perform blocking I/O operations (like reading large data files) in a dedicated **Data Acquisition Thread**. This prevents the main UI thread from freezing and ensures the application remains responsive. Communication with other threads is managed through Qt's Signals and Slots mechanism.
