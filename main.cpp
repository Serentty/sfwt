#include <iostream>
#include <string>
#include "PlanetGeneration.h"

using namespace std;

int main(){
/*Planet earth = planetGeneration();
earth.name = "Earth";

cout << "Planet " << earth.name << endl;
cout << "Mass : " << earth.mass << "Kg" << endl;
cout << "Diameter : " << earth.diameter << "m" << endl;
cout << "Gravity : " << earth.gravity << "G" << endl;
cout << "Temperature : " << earth.temperature << "K" << endl;
*/
cout << orbitalPeriodCalculation(149.60e6, 1.989e30);

return 0;
}
