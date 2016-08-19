#include "Entity.h"
#include "Vector.h"
#include <cstdint>

void Entity::move()
{
    this->location += this->velocity;
}
