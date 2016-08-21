#include <string>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include "Chunk.h"
#include "Entity.h"
#include "Vector.h"

uint8_t tileSize = 24; // 24x24 pixels
sf::Font *renderFont;
sf::Text characterBuffer;

void setFont(sf::Font *font)
{
    renderFont = font;
}

void render(Chunk chunk, sf::RenderWindow &window)
{
    tileSize = window.getSize().y / 16;
    characterBuffer.setFont(*renderFont);
    characterBuffer.setCharacterSize(tileSize);
    // Render tiles
    for(int y = 15; y >= 0; y--)
    {
        for(int x = 0; x <= 15; x++)
        {
            if(chunk.tiles[x][y][15].isSloped())
                characterBuffer.setString("n");
            else
                characterBuffer.setString("O");

            characterBuffer.setPosition(x * tileSize, window.getSize().y - y * tileSize);
            // Find correct colour
            if(chunk.tiles[x][y][15].blockMaterial == nullptr) // The block is not filled in
                characterBuffer.setFillColor(chunk.tiles[x][y][15].floorMaterial->colour);
            else
                characterBuffer.setFillColor(chunk.tiles[x][y][15].blockMaterial->colour);


            // Draw the character
            window.draw(characterBuffer);
        }
    }
    // Render entities
    characterBuffer.setFillColor(sf::Color::White);
    for(Entity *entity : chunk.entities)
    {
        std::string str(1, entity->character);
        characterBuffer.setString(str);
        characterBuffer.setPosition(entity->location.x * tileSize,
                                    window.getSize().y - entity->location.y * tileSize);
        window.draw(characterBuffer);
    }
}
