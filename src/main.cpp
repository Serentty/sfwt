#include <iostream>
#include <stdint.h>
#include <ncurses.h>
#include <stdint.h>
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
                player.velocity += Coordinates {0.0, 0.1, 0.0};
                break;
            case KEY_DOWN: // down
                player.velocity += Coordinates {0.0, -0.1, 0.0};
                break;
            case KEY_LEFT: // right
                player.velocity += Coordinates {-0.1, 0.0, 0.0};
                break;
            case KEY_RIGHT: // left
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
