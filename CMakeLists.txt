cmake_minimum_required(VERSION 3.6)
project(sfwt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lncurses -O3")

set(SOURCE_FILES
    src/Animal.h
    src/Calculations.cpp
    src/Calculations.h
        src/Chunk.h
    src/Colour.cpp
    src/Colour.h
        src/Vector.cpp
        src/Vector.h
    src/Ellipse.cpp
    src/Ellipse.h
    src/Entity.cpp
    src/Entity.h
    src/Lifeform.h
    src/main.cpp
    src/Material.cpp
    src/Material.h
    src/Organ.h
    src/PlanetGeneration.cpp
    src/PlanetGeneration.h
    src/Renderer.cpp
    src/Renderer.h
    src/Tile.h src/Chunk.cpp)

include_directories(.)
include_directories(src)

add_executable(sfwt ${SOURCE_FILES})