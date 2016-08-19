#include <cmath>
#include "Vector.h"

Vector Vector::operator+(const Vector &rightHandSide)
{
    Vector result;
    result.x = this->x + rightHandSide.x;
    result.y = this->y + rightHandSide.y;
    result.z = this->z + rightHandSide.z;
    return result;
}

Vector Vector::operator-(const Vector &rightHandSide)
{
    Vector result;
    result.x = this->x - rightHandSide.x;
    result.y = this->y - rightHandSide.y;
    result.z = this->z - rightHandSide.z;
    return result;
}

Vector Vector::operator*(const Vector &rightHandSide)
{
    Vector result;
    result.x = this->x * rightHandSide.x;
    result.y = this->y * rightHandSide.y;
    result.z = this->z * rightHandSide.z;
    return result;
}

Vector Vector::operator/(const Vector &rightHandSide)
{
    Vector result;
    result.x = this->x / rightHandSide.x;
    result.y = this->y / rightHandSide.y;
    result.z = this->z / rightHandSide.z;
    return result;
}

Vector Vector::cross(const Vector &rightHandSide)
{
    Vector result;
    result.x = (this->y * rightHandSide.z) - (this->z * rightHandSide.y);
    result.y = (this->z * rightHandSide.x) - (this->x * rightHandSide.z);
    result.z = (this->x * rightHandSide.y) - (this->y * rightHandSide.x);
    return result;
}

double Vector::dot(const Vector &rightHandSide)
{
    return (this->x * rightHandSide.x) + (this->y * rightHandSide.y) + (this->z * rightHandSide.z);
}

double Vector2D::findTheta(double x, double y)
{
    if (x == 0 && y == 0)
        return 0;
    return (std::atan(y / x) * 180) / std::M_PI;
}
