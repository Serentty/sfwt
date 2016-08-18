#ifndef ELLIPSE_H
#define ELLIPSE_H

double findDistanceBetweenPoints(double aX, double aY, double bX, double bY);
double findFoci(double semiMajorAxis, double semiMinorAxis);
double findEccentricity(double semiMajorAxis, double semiMinorAxis);
double findOrbitalPeriod(double semiMajorAxis);
double findTheta(double x, double y);

#endif
