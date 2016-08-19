#ifndef COORDINATES_H
#define COORDINATES_H

#include <cstdint>

struct Coordinates
{
    double x;
    double y;
    double z;
    // Operators
    Coordinates operator+(const Coordinates &rightHandSide);
    Coordinates operator-(const Coordinates &rightHandSide);
    Coordinates operator*(const Coordinates &rightHandSide);
    Coordinates operator/(const Coordinates &rightHandSide);
    inline void operator+=(const Coordinates &rightHandSide) { *this = *this + rightHandSide; };
    inline void operator-=(const Coordinates &rightHandSide) { *this = *this - rightHandSide; };
    inline void operator*=(const Coordinates &rightHandSide) { *this = *this * rightHandSide; };
    inline void operator/=(const Coordinates &rightHandSide) { *this = *this / rightHandSide; };
    Coordinates cross(const Coordinates &rightHandSide);
    double dot(const Coordinates &rightHandSide);
};

struct FlooredCoordinates
{
    int32_t x;
    int32_t y;
    int32_t z;
};

#endif
