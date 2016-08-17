#include <iostream>

#include "Calculations.h"
#include "Material.h"

double findMass(Material &material, double volume)
{
    if(volume < 0)
    {
        std::cerr << "Tried to find mass of negative volume" << std::endl;
        return 0;
    }
    return material.density * volume;
}

double findVolume(Material &material, double mass)
{
    if(mass < 0)
    {
        std::cerr << "Tried to find volume of negative mass" << std::endl;
        return 0;
    }
    if(material.density == 0)
    {
        std::cerr << "Tried to find volume of zero mass" << std::endl;
        return 0;
    }
    return mass / material.density;
}
