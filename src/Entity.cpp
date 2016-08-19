#include "Entity.h"
#include "Vector.h"
#include <cstdint>
#include <cmath>

void Entity::tick()
{
    this->location += (this->velocity / 1000.0);
}

double Entity::findTotalMass()
{
    double totalMass = this->mass; // Start with the mass of this entity
    for(Entity *entity : this->contents)
        totalMass += entity->findTotalMass();
    return totalMass;
}

double Entity::findKineticEnergy()
{
    return (this->mass * std::pow(this->findSpeed(), 2)) / 2.0;
}