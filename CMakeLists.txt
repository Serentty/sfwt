cmake_minimum_required(VERSION 3.6)
project(sfwt)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -lsfml-system -lsfml-window -lsfml-graphics -lyaml-cpp -O3")

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

file(COPY Resources DESTINATION .)

add_executable(sfwt ${SOURCE_FILES})

# SFML

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()