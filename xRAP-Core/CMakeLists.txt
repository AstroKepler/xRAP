cmake_minimum_required(VERSION 3.31)
project(xRAP_Core)

set(CMAKE_CXX_STANDARD 23)

set(DOM_CORE ./core)
set(DOM_SOLVER ./solvers)

#Include the directories and now your cpp files will recognize your headers
include_directories(${DOM_CORE})
include_directories(${DOM_SOLVER})

set(
        SOURCE_FILES
        main.cpp
        ${DOM_SOLVER}/temperature_solver.h
        ${DOM_SOLVER}/temperature_solver.cpp
        ${DOM_CORE}/xRAP_core.h
        ${DOM_CORE}/xRAP_core.cpp
        ${DOM_CORE}/xRAP_core-height.cpp
        ${DOM_CORE}/xRAP_core-height.h
        ${DOM_CORE}/xRAP_core-save.cpp
        ${DOM_CORE}/xRAP_core-save.h
)
add_executable(untitled ${SOURCE_FILES})