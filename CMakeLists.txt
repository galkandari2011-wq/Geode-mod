cmake_minimum_required(VERSION 3.21)
project(PredictiveInputBuffer)

find_package(Geode REQUIRED)

add_geode_mod(PredictiveInputBuffer
    src/main.cpp
)
