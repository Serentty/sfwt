#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <math.h>
#include <stdint.h>
#include "Vector.h"

class Entity
{
public:
    Vector location; // Location within the chunk in metres
    Vector velocity; // Velocity relative to the coordinate grid in metres / second
    // Contents (eg. organs of living things, contents of a box, etc.)
    std::vector<Entity*> contents;
    // The character used to represent the entity in the world
    char character;
    // Location and movement
    inline FlooredVector findFlooredCoordinates()
    {
        return FlooredVector {int32_t(std::floor(location.x)),
                                   int32_t(std::floor(location.y)),
                                   int32_t(std::floor(location.z))};
    };
    inline void relocateWithinChunk(Vector destination)
    {
        this->location = destination;
    };
    void move();
};

#endif
