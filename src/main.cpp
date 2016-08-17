#include <iostream>
#include <string>
#include <ncurses.h>
#include "Material.h"
#include "Calculations.h"
#include "Chunk.h"

using namespace std;

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
    endwin();
    return 0;
}
