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
include_directories(${CMAKE_SOURCE_DIR}/include)  # Includes project-specific headers in 'include/' folder

# Source files
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)  # Recursively gather all .cpp files in 'src/'

# Header files (ensure headers are visible in the solution explorer)
file(GLOB_RECURSE HEADERS ${CMAKE_SOURCE_DIR}/include/*.h)

# Add executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})  # Add both sources and headers to the executable

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)

# Post-build steps for Windows (to copy SFML DLLs)
if (WIN32)
    # Ensure DLLs are copied to the output directory after build
    file(COPY "${SFML_DIR}/../../../bin/sfml-system-2.dll" DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY "${SFML_DIR}/../../../bin/sfml-window-2.dll" DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY "${SFML_DIR}/../../../bin/sfml-graphics-2.dll" DESTINATION ${CMAKE_BINARY_DIR})
endif()

# Optional message if SFML is not found (Windows specific)
if (WIN32 AND NOT SFML_FOUND)
    message(STATUS "SFML not found. Consider using vcpkg to install SFML automatically.")
endif()
