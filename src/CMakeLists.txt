# CMake Version
cmake_minimum_required(VERSION 3.24)

# Project Name
project(Json VERSION 0.1.1)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add config.h
configure_file(config.h.in config.h)

# Download CPM.cmake
set(CPM_DOWNLOAD_VERSION 0.38.2) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()
include(${CPM_DOWNLOAD_LOCATION})

# Add package: nlohmann/json
CPMAddPackage(
	NAME nlohmann_json
	GITHUB_REPOSITORY nlohmann/json
	VERSION 3.11.2
)

# Add package: shoejunk/stk-log
CPMAddPackage(
	NAME log
	GITHUB_REPOSITORY shoejunk/log
	VERSION 0.2.0
)

# Add executable
add_executable(Json main.cpp)

# Include directories
target_include_directories(Json PUBLIC "${PROJECT_BINARY_DIR}")

# Link libraries
target_link_libraries(Json PUBLIC nlohmann_json::nlohmann_json Log)

