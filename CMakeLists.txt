cmake_minimum_required(VERSION 4.2)
project(PhysicsSimulation)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED CONFIG)

add_executable(PhysicsSimulation main.cpp
        graphics/include/Window.h
        graphics/src/Window.cpp
        graphics/include/Circle.h
        graphics/src/Circle.cpp
        physics/include/Constants.h
        physics/src/EulerMethods.cpp
        physics/include/EulerMethods.h
        physics/src/Particle.cpp
        physics/include/Particle.h
        utils/src/Utils.cpp
        utils/include/Utils.h
        utils/include/Vector2.h
)

target_link_libraries(PhysicsSimulation PRIVATE SDL2::SDL2)
