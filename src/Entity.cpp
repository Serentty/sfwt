#include "Entity.h"
#include "Vector.h"
#include <stdint.h>

void Entity::move()
{
    this->location += this->velocity;
}
