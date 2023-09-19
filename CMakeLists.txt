cmake_minimum_required(VERSION 3.1)
project(RealSenseExample)

# Set C++11 as the standard for the project
set(CMAKE_CXX_STANDARD 11)

# Find the librealsense2 installed package
find_package(realsense2 REQUIRED)

# Add the executable
add_executable(${PROJECT_NAME} main.cpp)

# Link librealsense2 to the target
target_link_libraries(${PROJECT_NAME} ${realsense2_LIBRARY})

