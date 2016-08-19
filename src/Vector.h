#ifndef COORDINATES_H
#define COORDINATES_H

#include <cstdint>

const double PI = 3.14159265358979323846;

struct Vector
{
    double x;
    double y;
    double z;
    // Conversion
    double findMagnitude();
    // Operators
    Vector operator+(const Vector &rightHandSide);
    Vector operator-(const Vector &rightHandSide);
    Vector operator*(const Vector &rightHandSide);
    Vector operator/(const Vector &rightHandSide);
    inline void operator+=(const Vector &rightHandSide) { *this = *this + rightHandSide; };
    inline void operator-=(const Vector &rightHandSide) { *this = *this - rightHandSide; };
    inline void operator*=(const Vector &rightHandSide) { *this = *this * rightHandSide; };
    inline void operator/=(const Vector &rightHandSide) { *this = *this / rightHandSide; };
    Vector operator+(const double &rightHandSide);
    Vector operator-(const double &rightHandSide);
    Vector operator*(const double &rightHandSide);
    Vector operator/(const double &rightHandSide);
    inline void operator+=(const double &rightHandSide) { *this = *this + rightHandSide; };
    inline void operator-=(const double &rightHandSide) { *this = *this - rightHandSide; };
    inline void operator*=(const double &rightHandSide) { *this = *this * rightHandSide; };
    inline void operator/=(const double &rightHandSide) { *this = *this / rightHandSide; };
    Vector cross(const Vector &rightHandSide);
    double dot(const Vector &rightHandSide);
};

struct Vector2D
{
    double x;
    double y;
    double findTheta(double x, double y);
};

struct FlooredVector
{
    std::int32_t x;
    std::int32_t y;
    std::int32_t z;
};

#endif
