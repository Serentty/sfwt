#include <iostream>
#include <ncurses.h>
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
    timeout(0);
    attron(A_BOLD);
    printw("Space Fortress");
    attroff(A_BOLD);
    printw(" (Working Title)\n");
    refresh();
    getch();
    ch.tiles[4][4][15].attributes[0] = true;
    Animal player;
    player.character = '@';
    Animal dude;
    dude.character = '&';
    player.mass = 60;
    player.location.x = 2.0;
    player.location.y = 2.0;
    player.location.z = 15.0;
    dude.mass = 40;
    dude.location.x = 4.0;
    dude.location.y = 4.0;
    dude.location.z = 15.0;
    ch.entities.push_back(&player);
    ch.entities.push_back(&dude);
    int key = 0;
    int ticks = 0;
    for(;;)
    {
        key = getch();
        ch.tick();
        ticks++;
        switch(key)
        {
            case KEY_UP: // up
                player.velocity += Vector {0.0, 0.1, 0.0};
                break;
            case KEY_DOWN: // down
                player.velocity += Vector {0.0, -0.1, 0.0};
                break;
            case KEY_LEFT: // right
                player.velocity += Vector {-0.1, 0.0, 0.0};
                break;
            case KEY_RIGHT: // left
                player.velocity += Vector {0.1, 0.0, 0.0};
                break;
            case 'q': // quit
                endwin();
                return 0;
                break;
        }
        if(ticks % 1000 == 0)
        {
            clear();
            printw(render(ch).c_str());
            printw("TIME ELAPSED: %f SECONDS\n", ticks / 1000.0);
            printw("SPEED: %f METRES / SECOND\n", player.findSpeed());
            printw("KINETIC ENERGY: %f JOULES\n", player.findKineticEnergy());
            printw("DISTANCE FROM DUDE: %f METRES", player.location.findDistance(dude.location));
            refresh();
        }
    }
    getch();
    endwin();

    return 0;
}
