#include <iostream>
#include <string>
#include "Material.h"
#include "Calculations.h"
#include "Chunk.h"

using namespace std;

int main()
{
    Chunk ch;
    for(int x = 0; x < 16; x++)
    {
        for(int y = 0; y < 16; y++)
            cout << ch.tiles[x][y].material << " ";
        cout << endl;
    }
}
