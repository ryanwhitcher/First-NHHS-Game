cmake_minimum_required(VERSION 3.15)

# Project settings
project(MySFMLGame)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML setup
set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics REQUIRED)

# Add ImGui-SFML
add_subdirectory(libs/imgui-sfml)
include_directories(libs/imgui-sfml)

# Include directories
include_directories(include libs/SFML/include)

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

# Link ImGui-SFML
target_link_libraries(${PROJECT_NAME} imgui-sfml)
