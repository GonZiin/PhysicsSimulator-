cmake_minimum_required(VERSION 4.2)
project(PhysicsSimulation)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED CONFIG)

add_executable(PhysicsSimulation main.cpp)

target_link_libraries(PhysicsSimulation PRIVATE SDL2::SDL2)
