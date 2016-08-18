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
    player.x = 2;
    player.y = 2;
    player.z = 15;
    ch.entities.push_back(&player);
    uint16_t key;
    for(;;)
    {
        key = getch();
        switch(key)
        {
            case KEY_UP: // up
                player.relocateWithinChunk(player.x, player.y + 1, player.z);
                break;
            case KEY_DOWN: // down
                player.relocateWithinChunk(player.x, player.y - 1, player.z);
                break;
            case KEY_LEFT: // right
                player.relocateWithinChunk(player.x - 1, player.y, player.z);
                break;
            case KEY_RIGHT: // left
                player.relocateWithinChunk(player.x + 1, player.y, player.z);
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
