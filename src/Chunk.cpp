#include <cstdint>
#include "Chunk.h"

void Chunk::tick()
{
    for(Entity *entity : this->entities)
        entity->tick();
}

void Chunk::run(std::uint16_t ticks)
{
    for(std::uint16_t i = 0; i < ticks; i++)
        this->tick();
}