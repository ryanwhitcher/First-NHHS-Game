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

# Platform-specific DLL handling
if (WIN32)
    # Windows specific settings
    set(SFML_DIR "path/to/SFML")
elseif(APPLE)
    # macOS specific settings
    find_package(SFML REQUIRED COMPONENTS system window graphics)
elseif(UNIX)
    # Linux specific settings
    find_package(SFML REQUIRED COMPONENTS system window graphics)
endif()



# Optional: Recommend the use of vcpkg for dependency management
if (WIN32 AND NOT SFML_FOUND)
    message(STATUS "SFML not found. Consider(nvm) using vcpkg to install SFML automatically.")
endif()
