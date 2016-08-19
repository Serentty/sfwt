#ifndef CHUNK_H
#define CHUNK_H

#include <vector>
#include <cstdint>
#include "Tile.h"
#include "Entity.h"

class Chunk
{
public:
    Tile tiles[16][16][16];
    std::vector<Entity*> entities;
    void tick();
    void run(std::uint16_t ticks);
};

#endif
