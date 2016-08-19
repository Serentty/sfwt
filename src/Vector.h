#ifndef COORDINATES_H
#define COORDINATES_H

#include <stdint.h>

struct Vector
{
    double x;
    double y;
    double z;
    // Operators
    Vector operator+(const Vector &rightHandSide);
    Vector operator-(const Vector &rightHandSide);
    Vector operator*(const Vector &rightHandSide);
    Vector operator/(const Vector &rightHandSide);
    inline void operator+=(const Vector &rightHandSide) { *this = *this + rightHandSide; };
    inline void operator-=(const Vector &rightHandSide) { *this = *this - rightHandSide; };
    inline void operator*=(const Vector &rightHandSide) { *this = *this * rightHandSide; };
    inline void operator/=(const Vector &rightHandSide) { *this = *this / rightHandSide; };
    Vector cross(const Vector &rightHandSide);
    double dot(const Vector &rightHandSide);
};

struct Vector2D
{
    double x;
    double y;
};

struct FlooredVector
{
    int32_t x;
    int32_t y;
    int32_t z;
};

#endif
