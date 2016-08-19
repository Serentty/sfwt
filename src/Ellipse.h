#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Vector.h"

double findDistanceBetweenPoints(double aX, double aY, double bX, double bY);
double findFoci(double semiMajorAxis, double semiMinorAxis);
double findEccentricity(double semiMajorAxis, double semiMinorAxis);
double findOrbitalPeriod(double semiMajorAxis);
double findTheta(double x, double y);
double findSemiMinorAxis(double semiMajorAxis, double eccentricity);
Vector2D findEllipseAndLineIntersection(double semiMajorAxis, double eccentricity, double theta,
                                        double lineXDisplacement, double ellipseXDisplacement,
                                        double ellipseYDisplacement);

#endif
