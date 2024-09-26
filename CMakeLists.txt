cmake_minimum_required(VERSION 3.15)

# Project settings
project(FirstNHHSGame)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML setup
set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics REQUIRED)



# Include directories
include_directories(include libs/SFML/include)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)


