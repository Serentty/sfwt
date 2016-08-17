#include <iostream>
#include <string>
#include "Material.h"
#include "Calculations.h"

using namespace std;

int main()
{
    Material air(1.275);
    cout << findMass(air, -2) << endl;
}
