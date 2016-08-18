#include <random>
#include <string>
#include <math.h>

const double GRAVITATIONAL_CONSTANT = 6.67408E-11;
const double PI = 3.141592;

class Planet
{
    public:
        std::string name;
        double diameter; // metres
        double mass; // kilograms
        double gravity; // m/s^2
        double temperature; // kelvin
        //Orbital data

    private:
        double esi; // Earth similarity index (From 0 to 1)
};

// Orbital distances from 40e6 to

Planet generatePlanet(double diameter = 12742000, double mass = 5.972e21, double gravity = 9.81, double temperature = 288)
{
    Planet bob;
    bob.diameter = diameter;
    bob.mass = mass;
    bob.gravity = gravity;
    bob.temperature = temperature;
    return bob;
}

double calculateOrbitalPeriod(double semiMajorAxis, double mass) // Mass of the more massive body.
{
    return 2 * PI * sqrt(pow(semiMajorAxis, 3) / GRAVITATIONAL_CONSTANT);
}
