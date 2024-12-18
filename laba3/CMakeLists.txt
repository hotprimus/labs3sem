cmake_minimum_required(VERSION 3.14)
project(HistogramGenerator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
find_package(Qt5 COMPONENTS Widgets Charts REQUIRED)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)

set(HEADERS
    ${SRC_DIR}/MainWindow.h
)

set(SOURCES
    ${SRC_DIR}/main.cpp
    ${SRC_DIR}/MainWindow.cpp
    ${SRC_DIR}/Person.cpp
    ${SRC_DIR}/Utils.cpp
)

include_directories(${SRC_DIR})

add_executable(HistogramGenerator ${SOURCES} ${HEADERS})
target_link_libraries(HistogramGenerator PRIVATE Qt5::Widgets Qt5::Charts)

add_custom_command(TARGET HistogramGenerator POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${RESOURCES_DIR}
        $<TARGET_FILE_DIR:HistogramGenerator>/resources)

set(TEST_SOURCES
    ${SRC_DIR}/Person.cpp
    ${SRC_DIR}/Utils.cpp
    ${SRC_DIR}/tests/main_tests.cpp
    ${SRC_DIR}/tests/PersonTest.h
    ${SRC_DIR}/tests/HistogramBuilderTest.h
)

add_executable(Tests ${TEST_SOURCES})
target_include_directories(Tests PRIVATE ${SRC_DIR})
target_compile_definitions(Tests PRIVATE -DTESTING)

add_custom_command(TARGET Tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${RESOURCES_DIR}
        $<TARGET_FILE_DIR:Tests>/resources)
