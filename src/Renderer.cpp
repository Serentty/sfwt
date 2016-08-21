#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Renderer.h"
#include "Chunk.h"
#include "Entity.h"
#include "Vector.h"

const uint8_t TILE_SIZE = 24; // 24x24 pixels
sf::Font *renderFont;
sf::Text characterBuffer;

void setFont(sf::Font *font)
{
    renderFont = font;
}

void render(Chunk chunk, sf::RenderWindow &window)
{
    characterBuffer.setFont(*renderFont);
    characterBuffer.setCharacterSize(TILE_SIZE);
    characterBuffer.setFillColor(sf::Color::White);
    for(int y = 15; y >= 0; y--)
    {
        for(int x = 0; x <= 15; x++)
        {
            if(chunk.tiles[x][y][15].isSloped())
                characterBuffer.setString("n");
            else
                characterBuffer.setString("O");

            characterBuffer.setPosition(x * TILE_SIZE, window.getSize().y - y * TILE_SIZE);
            window.draw(characterBuffer);
        }
    }
    for(Entity *entity : chunk.entities)
    {
        std::string str(1, entity->character);
        characterBuffer.setString(str);
        characterBuffer.setPosition(entity->location.x * TILE_SIZE,
                                    window.getSize().y - entity->location.y * TILE_SIZE);
        window.draw(characterBuffer);
    }
}
