#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <cmath>
#include <cstdint>
#include "Vector.h"

class Entity
{
public:
    double mass; // Mass in kilograms
    char character; // The character used to represent the entity in the world
    Vector location; // Location within the chunk in metres
    Vector velocity; // Velocity relative to the coordinate grid in metres / second
    std::vector<Entity*> contents; // Contents (eg. organs of living things, contents of a box, etc.)

    // Location and movement
    inline FlooredVector findFlooredCoordinates()
    {
        return FlooredVector {std::int32_t(std::floor(location.x)),
                              std::int32_t(std::floor(location.y)),
                              std::int32_t(std::floor(location.z))};
    };
    inline void relocateWithinChunk(Vector destination)
    {
        this->location = destination;
    };
    inline double findSpeed() { return velocity.findMagnitude(); };
    double findTotalMass(); // Find the total mass, including contents
    double findKineticEnergy(); // Find the kinetic energy in joules
    void tick();
};

#endif
