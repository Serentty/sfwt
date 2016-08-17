#include <iostream>
#include <string>
#include "Material.h"
#include "Calculations.h"

using namespace std;

int main()
{
    Material air(1.275);
    for(int i = 0; i < 100000000; i++)
    {
        findMass(air, 2000);
    }
}
