#include "Renderer.h"
#include "Chunk.h"
#include "Entity.h"

std::string render(Chunk chunk)
{
    std::string renderedMap;
    for(int y = 15; y >= 0; y--)
    {
        for(int x = 0; x <= 15; x++)
        {
            for(Entity *entity : chunk.entities)
            {
                if(entity->x == x && entity->y == y)
                {
                    renderedMap.push_back(entity->character);
                    goto nextTile;
                }
            }
            if(chunk.tiles[x][y].isSloped())
                renderedMap.push_back('n');
            else
                renderedMap.push_back('O');

            nextTile:
            continue;
        }
        renderedMap.push_back('\n');
    }
    return renderedMap;
}
