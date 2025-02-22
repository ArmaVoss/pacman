cmake_minimum_required(VERSION 3.29)
project(pacman)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_REQUIRED ON)

add_subdirectory(vendor)
add_executable(pacman main.cpp classes/Renderer.cpp classes/Map.cpp)
target_link_libraries(pacman PRIVATE vendor)
