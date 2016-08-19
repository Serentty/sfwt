#include <iostream>
#include <string>
#include <ncurses.h>
#include "Material.h"
#include "Calculations.h"
#include "Chunk.h"
#include "Animal.h"
#include "Renderer.h"

using namespace std;

Chunk ch;

int main()
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    attron(A_BOLD);
    printw("Space Fortress");
    attroff(A_BOLD);
    printw(" (Working Title)\n");
    refresh();
    getch();
    ch.tiles[4][4][15].attributes[0] = true;
    Animal player;
    player.character = '@';
    player.location.x = 2.0;
    player.location.y = 2.0;
    player.location.z = 15.0;
    ch.entities.push_back(&player);
    uint16_t key;
    for(;;)
    {
        key = getch();
        player.move();
        switch(key)
        {
            case KEY_UP: // up
                //player.relocateWithinChunk(Coordinates {player.location.x, player.location.y + 0.5, player.location.z});
                player.velocity += Coordinates {0.0, 0.1, 0.0};
                break;
            case KEY_DOWN: // down
                //player.relocateWithinChunk(Coordinates {player.location.x, player.location.y - 0.5, player.location.z});
                player.velocity += Coordinates {0.0, -0.1, 0.0};
                break;
            case KEY_LEFT: // right
                //player.relocateWithinChunk(Coordinates {player.location.x - 0.5, player.location.y, player.location.z});
                player.velocity += Coordinates {-0.1, 0.0, 0.0};
                break;
            case KEY_RIGHT: // left
                //player.relocateWithinChunk(Coordinates {player.location.x + 0.5, player.location.y, player.location.z});
                player.velocity += Coordinates {0.1, 0.0, 0.0};
                break;
            case 'q': // quit
                endwin();
                return 0;
                break;
        }
        clear();
        printw(render(ch).c_str());
        refresh();
    }
    getch();
    endwin();

    return 0;
}
