cmake_minimum_required(VERSION 3.10...3.22)  # Ensures compatibility
project(BowlingGame)

# Set the C++ Standard (optional but recommended)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Add the executable
add_executable(BowlingGame main.cpp bowlinggame.cpp)
