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
    player.mass = 60;
    player.radius = 0.49;
    player.location.x = 2.0;
    player.location.y = 2.0;
    player.location.z = 15.0;
    for(int i = 0; i < 10; i++)
    {
        Animal *dude = new Animal();
        dude->character = '&';
        dude->mass = 40;
        dude->radius = 0.49;
        dude->location.x = i;
        dude->location.y = 8.0;
        dude->location.z = 15.0;
        ch.entities.push_back(dude);
    }
    ch.entities.push_back(&player);
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
            refresh();
        }
    }
    getch();
    endwin();

    return 0;
}
