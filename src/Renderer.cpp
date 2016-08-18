#include "Renderer.h"
#include "Chunk.h"
#include "Entity.h"

std::string render(Chunk chunk)
{
    std::string renderedMap;
    for(int x = 0; x < 16; x++)
    {
        for(int y = 0; y < 16; y++)
        {
            for(Entity entity : chunk.entities)
            {
                if(entity.x == x && entity.y == y)
                {
                    renderedMap.append(entity.character);
                    goto nextTile;
                }
            }
            else if(chunk.tiles[x][y].isSloped())
                renderedMap.append("n");
            else
                renderedMap.append("O");

            nextTile:
        }
        renderedMap.append("\n");
    }
    return renderedMap;
}
