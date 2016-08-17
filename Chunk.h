#ifndef CHUNK_H
#define CHUNK_H

#include "Tile.h"

class Chunk
{
public:
    Tile tiles[][16];
    Chunk();
    ~Chunk();
};

#endif
