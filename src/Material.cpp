#include <iostream>
#include "Material.h"

Material::Material(double density)
{
    if(density >= 0)
        this->density = density;
    else
    {
        std::cerr << "Tried to create material with negative density" << std::endl;
        this->density = 0;
    }
}
