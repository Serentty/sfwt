#ifndef PLANETGENERATION_H
#define PLANETGENERATION_H

#include <string>

class Planet
{
   public:
       std::string name;
       double diameter;
       double mass;
       double gravity;
       double temperature;
       double esi;
};

Planet generatePlanet(double diameter = 12742000,double mass = 5.972e21, double gravity = 1, double temperature = 288);
double calculateOrbitalPeriod(double semiMajorAxis, double mass);
#endif
