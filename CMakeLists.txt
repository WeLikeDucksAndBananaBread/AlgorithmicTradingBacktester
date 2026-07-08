cmake_minimum_required(VERSION 4.2)
project(Algorithmic_Trading_Backtester)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Qt6_ROOT "$ENV{Qt6_ROOT}" CACHE PATH "Qt6 installation root (for example, /opt/Qt/6.11.1/gcc_64)")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Test)

# Core library
add_library(backtester_core
        src/core/AppInfo.cpp
)

target_include_directories(backtester_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(backtester_core
        PUBLIC
        Qt6::Core
)

# Data Acquisition Library
add_library(backtester_data
        src/data/cache/DataCache.h
        src/data/parsers/csv_parser.cpp
        src/data/parsers/json_parser.cpp
        src/data/cache/data_cache.cpp
        src/data/models/bar.cpp
        src/data/models/tick.cpp
)

target_include_directories(backtester_data
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(backtester_data
        PUBLIC
        backtester_core
        Qt6::Core
)

# Backtesting Engine Library
add_library(backtester_logic
        src/logic/engine/backtest_engine.cpp
        src/logic/engine/simulation_loop.cpp
        src/logic/strategies/strategy_base.cpp
        src/logic/metrics/performance_metrics.cpp
        src/logic/events/event_handler.cpp
)

target_include_directories(backtester_logic
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(backtester_logic
        PUBLIC
        backtester_core
        Qt6::Core
)

# Strategy Translator Library
add_library(backtester_strategy
        src/strategy/parser/rule_parser.cpp
        src/strategy/translator/rule_translator.cpp
        src/strategy/indicators/sma.cpp
        src/strategy/indicators/ema.cpp
        src/strategy/conditions/condition_base.cpp
)

target_include_directories(backtester_strategy
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(backtester_strategy
        PUBLIC
        backtester_core
        backtester_logic
        Qt6::Core
)

# UI Library
add_library(backtester_ui
        ui/MainWindow.cpp
        ui/strategy_builder/strategy_builder_widget.cpp
        ui/charts/candlestick_chart.cpp
        ui/charts/equity_curve_chart.cpp
        ui/dashboard/dashboard_widget.cpp
        ui/settings/settings_widget.cpp
        ui/widgets/custom_widgets.cpp
)

target_include_directories(backtester_ui
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(backtester_ui
        PUBLIC
        backtester_core
        backtester_data
        backtester_logic
        backtester_strategy
        Qt6::Widgets
)

add_executable(Algorithmic_Trading_Backtester
        src/main.cpp
)

target_link_libraries(Algorithmic_Trading_Backtester
        PRIVATE
        backtester_ui
)

add_custom_target(run
    COMMAND $<TARGET_FILE:Algorithmic_Trading_Backtester>
    DEPENDS Algorithmic_Trading_Backtester
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

include(CTest)
if(BUILD_TESTING)
    enable_testing()

    # Core tests
    add_executable(AppInfoTests tests/AppInfoTests.cpp)
    target_link_libraries(AppInfoTests PRIVATE backtester_core Qt6::Test)
    add_test(NAME AppInfoTests COMMAND AppInfoTests)

    # Data tests
    add_executable(DataCacheTests tests/data/DataCacheTests.cpp)
    target_link_libraries(DataCacheTests PRIVATE backtester_data Qt6::Test Qt6::Core)
    add_test(NAME DataCacheTests COMMAND DataCacheTests)

    add_executable(CSVParserTests tests/data/parsers/CSVParserTests.cpp)
    target_link_libraries(CSVParserTests PRIVATE backtester_data Qt6::Test Qt6::Core)
    add_test(NAME CSVParserTests COMMAND CSVParserTests)

    # Logic tests
    add_executable(BacktestEngineTests tests/logic/engine/BacktestEngineTests.cpp)
    target_link_libraries(BacktestEngineTests PRIVATE backtester_logic Qt6::Test Qt6::Core)
    add_test(NAME BacktestEngineTests COMMAND BacktestEngineTests)

    add_executable(PerformanceMetricsTests tests/logic/metrics/PerformanceMetricsTests.cpp)
    target_link_libraries(PerformanceMetricsTests PRIVATE backtester_logic Qt6::Test Qt6::Core)
    add_test(NAME PerformanceMetricsTests COMMAND PerformanceMetricsTests)

    # Strategy tests
    add_executable(RuleParserTests tests/strategy/parser/RuleParserTests.cpp)
    target_link_libraries(RuleParserTests PRIVATE backtester_strategy Qt6::Test Qt6::Core)
    add_test(NAME RuleParserTests COMMAND RuleParserTests)

    add_executable(SMATests tests/strategy/indicators/SMATests.cpp)
    target_link_libraries(SMATests PRIVATE backtester_strategy Qt6::Test Qt6::Core)
    add_test(NAME SMATests COMMAND SMATests)

    # UI tests
    add_executable(StrategyBuilderWidgetTests tests/ui/StrategyBuilderWidgetTests.cpp)
    target_link_libraries(StrategyBuilderWidgetTests PRIVATE backtester_ui Qt6::Test Qt6::Widgets)
    add_test(NAME StrategyBuilderWidgetTests COMMAND StrategyBuilderWidgetTests)

    add_executable(CandlestickChartTests tests/ui/charts/CandlestickChartTests.cpp)
    target_link_libraries(CandlestickChartTests PRIVATE backtester_ui Qt6::Test Qt6::Widgets)
    add_test(NAME CandlestickChartTests COMMAND CandlestickChartTests)

    add_custom_target(run_tests
        COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
endif()
