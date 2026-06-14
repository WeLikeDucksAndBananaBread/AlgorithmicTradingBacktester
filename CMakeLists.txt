cmake_minimum_required(VERSION 4.2)
project(Algorithmic_Trading_Backtester)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(Qt6_ROOT "$ENV{Qt6_ROOT}" CACHE PATH "Qt6 installation root (for example, /opt/Qt/6.11.1/gcc_64)")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

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

add_library(backtester_ui
        ui/MainWindow.cpp
)
target_include_directories(backtester_ui
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(backtester_ui
        PUBLIC
        backtester_core
        Qt6::Widgets
)

add_executable(Algorithmic_Trading_Backtester
        src/main.cpp
)
target_link_libraries(Algorithmic_Trading_Backtester
        PRIVATE
        backtester_ui
)

include(CTest)
if(BUILD_TESTING)
    add_executable(backtester_tests
            tests/AppInfoTests.cpp
    )
    target_include_directories(backtester_tests
            PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
    target_link_libraries(backtester_tests
            PRIVATE
            backtester_core
    )
    add_test(NAME AppInfoTests COMMAND backtester_tests)
endif()

