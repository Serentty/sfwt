#include "Chunk.h"
#include "Tile.h"

Chunk::Chunk()
{
    this->tiles = new Tile[16][16];
}

Chunk::~Chunk()
{
    delete [] zthis->tiles;
}
