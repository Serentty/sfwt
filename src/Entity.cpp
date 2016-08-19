#include "Entity.h"
#include "Coordinates.h"
#include <cstdint>

void Entity::move()
{
    this->location += this->velocity;
}
