#ifndef TILE_H
#define TILE_H

#include <vector>
#include <bitset>
#include "Material.h"

class Tile
{
public:
    Material *material;
    std::bitset<16> attributes;
    inline bool isSloped() { return this->attributes[0]; };
};

#endif
