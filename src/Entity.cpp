#include <cstdint>
#include <cmath>
#include <vector>
#include <ncurses.h>
#include "Entity.h"
#include "Vector.h"

void Entity::tick(std::vector<Entity*> &surroundingEntities)
{
    // Calculate where this entity wants to move
    Vector target = this->location + (this->velocity / 1000.0);
    double distance;
    // Check for collision
    bool hit = false;
    for(Entity *entity : surroundingEntities)
    {
        if(entity == this)
            continue; // Don't let an object collide with itself
        distance = target.findDistance(entity->location);
        if(distance <= this->radius + entity->radius)
        {
            this->velocity = Vector {0.0, 0.0, 0.0}; // Screetch!
            hit = true;
        }
    }

    if(!hit)
        this->location = target;
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