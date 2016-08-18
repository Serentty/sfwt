#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include <cstdint>

class Entity
{
public:
    // Location within the chunk
    uint8_t x;
    uint8_t y;
    // Contents (eg. organs of living things, contents of a box, etc.)
    std::vector<Entity*> contents;
    // The character used to represent the entity in the world
    char character;
    // Movement
    void relocateWithinChunk(int x, int y);
};

#endif
