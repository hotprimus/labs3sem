cmake_minimum_required(VERSION 3.16)
project(SortingApplication)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Test)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/Sequence
    ${PROJECT_SOURCE_DIR}/TypeOfSorts
    ${PROJECT_SOURCE_DIR}/UI
    ${PROJECT_SOURCE_DIR}/tests
)

set(SOURCES
    main.cpp
    UI/UI.cpp
)

set(HEADERS
    UI/UI.h
)

add_executable(SortingApp ${SOURCES} ${HEADERS})

target_link_libraries(SortingApp Qt6::Widgets)

set(TEST_SOURCES
    tests/SortingTests.cpp
)

add_executable(SortingTests ${TEST_SOURCES})

target_link_libraries(SortingTests Qt6::Test)
