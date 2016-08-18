#include "Entity.h"

void Entity::relocateWithinChunk(int x, int y)
{
    this->x = x;
    this->y = y;
}
