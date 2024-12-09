cmake_minimum_required(VERSION 3.10)
project(SortingProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS Core Widgets Charts Test REQUIRED)


add_executable(SortingProject
    main.cpp
    Person/Person.cpp
    UI/UI.cpp
    UI/UI.h
    UI/UI.ui
    Sequence/DynamicArray.h
    Sequence/MutableSequence.h
    TypeOfSorts/HeapSorter.h
    TypeOfSorts/ISorter.h
    TypeOfSorts/QuickSorter.h
    TypeOfSorts/ShellSorter.h
)


target_include_directories(SortingProject PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Person
    ${CMAKE_CURRENT_SOURCE_DIR}/Sequence
    ${CMAKE_CURRENT_SOURCE_DIR}/TypeOfSorts
)


target_link_libraries(SortingProject Qt5::Core Qt5::Widgets Qt5::Charts)


add_executable(SortingTests
    tests/SortingTests.cpp
    tests/SortingTests.h
    Person/Person.cpp
    Sequence/DynamicArray.h
    Sequence/MutableSequence.h
    TypeOfSorts/HeapSorter.h
    TypeOfSorts/ISorter.h
    TypeOfSorts/QuickSorter.h
    TypeOfSorts/ShellSorter.h
)


target_include_directories(SortingTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Person
    ${CMAKE_CURRENT_SOURCE_DIR}/Sequence
    ${CMAKE_CURRENT_SOURCE_DIR}/TypeOfSorts
)


target_link_libraries(SortingTests Qt5::Test Qt5::Core)

enable_testing()
add_test(NAME SortingTests COMMAND SortingTests)
