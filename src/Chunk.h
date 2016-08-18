#ifndef CHUNK_H
#define CHUNK_H

#include <vector>
#include "Tile.h"
#include "Entity.h"

class Chunk
{
public:
    Tile tiles[16][16][16];
    std::vector<Entity*> entities;
};

#endif
