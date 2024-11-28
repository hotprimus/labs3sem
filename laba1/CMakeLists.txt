cmake_minimum_required(VERSION 3.10)
project(SmartPointersProject)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


find_package(Qt5 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOUIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC OFF)


include_directories("${CMAKE_SOURCE_DIR}/include")


add_executable(functional_tests
    tests/functional_tests.cpp
)
target_include_directories(functional_tests PRIVATE "${CMAKE_SOURCE_DIR}/include")

add_executable(stress_tests
    tests/stress_tests.cpp
)
target_include_directories(stress_tests PRIVATE "${CMAKE_SOURCE_DIR}/include")

add_executable(SmartListTests
    tests/SmartListTests.cpp
)
target_include_directories(SmartListTests PRIVATE "${CMAKE_SOURCE_DIR}/include")

add_executable(SmartListSequenceTests
    tests/SmartListSequenceTests.cpp
)
target_include_directories(SmartListSequenceTests PRIVATE "${CMAKE_SOURCE_DIR}/include")


add_executable(ui_app
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
)

target_include_directories(ui_app PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_BINARY_DIR}"
)

target_link_libraries(ui_app Qt5::Widgets)
