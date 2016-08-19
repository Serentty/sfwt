#include "Coordinates.h"

Coordinates Coordinates::operator+(const Coordinates &rightHandSide)
{
    Coordinates result;
    result.x = this->x + rightHandSide.x;
    result.y = this->y + rightHandSide.y;
    result.z = this->z + rightHandSide.z;
    return result;
}

Coordinates Coordinates::operator-(const Coordinates &rightHandSide)
{
    Coordinates result;
    result.x = this->x - rightHandSide.x;
    result.y = this->y - rightHandSide.y;
    result.z = this->z - rightHandSide.z;
    return result;
}

Coordinates Coordinates::operator*(const Coordinates &rightHandSide)
{
    Coordinates result;
    result.x = this->x * rightHandSide.x;
    result.y = this->y * rightHandSide.y;
    result.z = this->z * rightHandSide.z;
    return result;
}

Coordinates Coordinates::operator/(const Coordinates &rightHandSide)
{
    Coordinates result;
    result.x = this->x / rightHandSide.x;
    result.y = this->y / rightHandSide.y;
    result.z = this->z / rightHandSide.z;
    return result;
}

Coordinates Coordinates::cross(const Coordinates &rightHandSide)
{
    Coordinates result;
    result.x = (this->y * rightHandSide.z) - (this->z * rightHandSide.y);
    result.y = (this->z * rightHandSide.x) - (this->x * rightHandSide.z);
    result.z = (this->x * rightHandSide.y) - (this->y * rightHandSide.x);
    return result;
}

double Coordinates::dot(const Coordinates &rightHandSide)
{
    return (this->x * rightHandSide.x) + (this->y * rightHandSide.y) + (this->z * rightHandSide.z);
}
