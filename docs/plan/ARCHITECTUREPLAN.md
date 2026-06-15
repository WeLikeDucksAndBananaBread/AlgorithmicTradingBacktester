# C++ AlgorithmicTradingBacktester - Architecture Plan
## Overview
___
This documentaion descirbes the architectural overview for the Backtester application.The application allows allows
users to manage load historical data,select a trading strategy,run the backtest,analyze the result.The system display the final
performace,profit or loss.
## High-Level Requirement
___
* Users can load CSV/JSON file
* Application display the Candlestick Chart/Equity curve
* Users can select strategy (e.g. Swing Trading,Daily Trading)
* Users can initial capital
* Users can run backtester
* View total profit and loss and current capital
## Technology Stack
___
### Backend
* **Language & Framework**: C++ 17, Qt 6.x
* **Build Tool**: CMake 4.2
* **Testing**: QTest
### DevOps
* **CI**:Github Actions 
## Modules
### Data Ingestion
* (`/src/data`)
* The historical data read from JSON/CSV file and pass parsed to the logic and UI
### LogicEngine
* (`/src/logic`)
* Execute the selected strategy on data,store data for view
### Interactive GUI:
* Qt-based interface featuring real-time candlestick and equity curve charts

