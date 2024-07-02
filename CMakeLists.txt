cmake_minimum_required(VERSION 3.16)
project(lekcja1)

set(CMAKE_CXX_STANDARD 14)

# Include directories
include_directories(include)

# Source files
set(SOURCES
        main.cpp
        src/Player.cpp
        src/GameModes.cpp
)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})