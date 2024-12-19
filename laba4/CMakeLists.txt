cmake_minimum_required(VERSION 3.14)
project(GraphAlgorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)   

find_package(Qt5 COMPONENTS Widgets Charts REQUIRED)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)

set(UI_FILES
    ${SRC_DIR}/MainWindow.ui
)

set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/Graph.cpp
    ${SRC_DIR}/Algorithms.cpp
    ${SRC_DIR}/MainWindow.cpp
    ${SRC_DIR}/HasseDiagram.cpp
)

set(HEADERS
    ${SRC_DIR}/Graph.h
    ${SRC_DIR}/Algorithms.h
    ${SRC_DIR}/MainWindow.h
    ${SRC_DIR}/HasseDiagram.h
)

include_directories(${SRC_DIR})

add_executable(GraphAlgorithms ${SOURCES} ${HEADERS} ${UI_FILES})

target_link_libraries(GraphAlgorithms PRIVATE Qt5::Widgets Qt5::Charts)

enable_testing()

add_executable(Tests
    ${SRC_DIR}/Graph.cpp
    ${SRC_DIR}/Algorithms.cpp
    ${SRC_DIR}/HasseDiagram.cpp
    ${SRC_DIR}/tests/main_tests.cpp
    ${SRC_DIR}/tests/GraphTest.h
    ${SRC_DIR}/tests/AlgorithmsTest.h
    ${SRC_DIR}/tests/HasseDiagramTest.h
)

target_include_directories(Tests PRIVATE ${SRC_DIR})

add_test(NAME GraphAlgorithmsTest COMMAND Tests)
