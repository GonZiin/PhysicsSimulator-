cmake_minimum_required(VERSION 4.2)
project(PhysicsSimulation)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED CONFIG)

add_executable(PhysicsSimulation main.cpp
        graphics/include/Window.h
        graphics/src/Window.cpp
        graphics/include/Circle.h
        graphics/src/Circle.cpp
)

target_link_libraries(PhysicsSimulation PRIVATE SDL2::SDL2)
