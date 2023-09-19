cmake_minimum_required(VERSION 3.1)
project(RealSenseExample)

# Set C++11 as the standard for the project
set(CMAKE_CXX_STANDARD 11)

# Find the librealsense2 installed package
find_package(realsense2 REQUIRED)
find_package(OpenCV REQUIRED)

# Create executable for hello_world
add_executable(hello_world hello_world.cpp)
# Link libraries to hello_world
target_link_libraries(hello_world ${realsense2_LIBRARY} ${OpenCV_LIBS})

# Create executable for capture
add_executable(capture capture.cpp)
# Link libraries to capture
target_link_libraries(capture ${realsense2_LIBRARY} ${OpenCV_LIBS})
