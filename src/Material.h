#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
public:
    // Physical properties
    double density; // kilograms per cubic metre
    double hardness; // as per the Vickers hardness test
    double ph; // acidity
    double freezingPoint; // kelvin
    double boilingPoint; // kelvin
    // Optics
    double translucency; // how much light passes through - 0 to 1
    double transparency; // how clearly an image can be seen - 0 to 1
    double indexOfRefraction; // index refraction for light
    double gloss; // measured in GU (gloss units)
    Material(double density);
};

#endif
