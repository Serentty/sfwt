#include "Entity.h"
#include "Coordinates.h"
#include <stdint.h>

void Entity::move()
{
    this->location += this->velocity;
}
