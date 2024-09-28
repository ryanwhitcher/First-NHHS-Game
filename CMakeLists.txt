cmake_minimum_required(VERSION 3.15)

# Project settings
project(FirstNHHSGame)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SFML setup
if(WIN32)
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/libs/SFML/lib/cmake/SFML")  # Adjust path to SFML
    find_package(SFML COMPONENTS system window graphics REQUIRED)
elseif(APPLE)
    # macOS SFML setup
    find_package(SFML REQUIRED COMPONENTS system window graphics)
elseif(UNIX)
    # Linux SFML setup
    find_package(SFML REQUIRED COMPONENTS system window graphics)
endif()

# Include directories
include_directories(include)  # Includes any project-specific headers

# Source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

# Post-build steps for Windows (to copy SFML DLLs)
if (WIN32)
    # Ensure DLLs are copied to the output directory
    file(COPY "${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-system-2.dll" DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY "${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-window-2.dll" DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY "${CMAKE_SOURCE_DIR}/libs/SFML/bin/sfml-graphics-2.dll" DESTINATION ${CMAKE_BINARY_DIR})
endif()

# Suggest using vcpkg for automatic SFML installation (optional)
if (WIN32 AND NOT SFML_FOUND)
    message(STATUS "SFML not found. Consider using vcpkg to install SFML automatically.")
endif()
