#include <cstdint>
#include "Chunk.h"

void Chunk::tick()
{
    for(Entity *entity : this->entities)
    {
        // First, find which tile the entity is closest to
        FlooredVector entityLocation = entity->findFlooredCoordinates();
        entity->tick(this->entities);
    }
}

void Chunk::run(std::uint16_t ticks)
{
    for(std::uint16_t i = 0; i < ticks; i++)
        this->tick();
}