cmake_minimum_required(VERSION 3.21)

project(PredictiveInputBuffer VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please set the GEODE_SDK environment variable.")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Use glob or list your source files explicitly
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_geode_mod(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
