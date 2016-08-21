#ifndef RENDERER_H
#define RENDERER_H

#include <string>
#include "Chunk.h"

void setFont(sf::Font *font);
void render(Chunk chunk, sf::RenderWindow &window);

#endif
