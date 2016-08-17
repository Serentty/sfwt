#include "Renderer.h"
#include "Chunk.h"

std::string render(Chunk chunk)
{
    std::string renderedMap;
    for(int x = 0; x < 16; x++)
    {
        for(int y = 0; y < 16; y++)
        {
            if(chunk.tiles[x][y].isSloped())
                renderedMap.append("n");
            else
                renderedMap.append("O");

        }
        renderedMap.append("\n");
    }
    return renderedMap;
}
