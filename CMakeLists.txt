cmake_minimum_required(VERSION 3.10)

# Make sure that compile commands will be generated
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Project name
project(LogAggregator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCES
    src/main.cpp
    src/LogGenerator.cpp
)

# Add executable
add_executable(LogAggregator ${SOURCES})

# Include directories
target_include_directories(LogAggregator PRIVATE include)
