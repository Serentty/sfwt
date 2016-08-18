#include "Entity.h"

void Entity::relocateWithinChunk(uint8_t x, uint8_t y, uint8_t z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
