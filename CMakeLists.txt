cmake_minimum_required(VERSION 3.11)
project(Cubobezier)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_SUPPRESS_REGENERATION ON)

include_directories("./src/")

file(GLOB_RECURSE SOURCE_FILES "./src/*.cpp")


# Find and include the GLFW package
find_package(glfw3 REQUIRED)

# Add your project executable
add_executable(Cubobezier ${SOURCE_FILES})

find_package(glfw3 REQUIRED)

# Link your project with the GLFW library
target_link_libraries(Cubobezier glfw GL)

#Remove CMakeCache.txt and cmake_install.cmake
file(REMOVE ${CMAKE_BINARY_DIR}/CMakeCache.txt)
file(REMOVE ${CMAKE_BINARY_DIR}/cmake_install.cmake)