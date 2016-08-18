#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <cmath>
#include <cstdint>
#include "Coordinates.h"

class Entity
{
public:
    // Location within the chunk
    Coordinates location;
    // Contents (eg. organs of living things, contents of a box, etc.)
    std::vector<Entity*> contents;
    // The character used to represent the entity in the world
    char character;
    // Location and movement
    inline FlooredCoordinates findFlooredCoordinates()
    {
        return FlooredCoordinates {int32_t(std::floor(location.x)),
                                   int32_t(std::floor(location.y)),
                                   int32_t(std::floor(location.z))};
    };
    inline void relocateWithinChunk(Coordinates destination)
    {
        this->location = destination;
    };
    void move(Coordinates delta);
};

#endif
