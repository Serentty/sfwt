#include <cmath>
#include "Vector.h"

const double GRAVITATIONAL_CONSTANT = 6.674e-11;
const double PI = 3.141592;

double findDistanceBetweenPoints(double aX, double aY, double bX, double bY)
{
    return sqrt(pow((bX - aX), 2) + pow((bY - aY), 2));
}

double findFoci(double semiMajorAxis, double semiMinorAxis)
{
    if (semiMinorAxis > semiMajorAxis)
    {
        double temp = semiMajorAxis;
        semiMajorAxis = semiMinorAxis;
        semiMinorAxis = temp;
    }
    return sqrt(pow(semiMajorAxis, 2) - pow(semiMinorAxis, 2));
}

// eccentricity = distance from the center to a focus Divided by the distance from that focus to a vertex
double findEccentricity(double semiMajorAxis, double semiMinorAxis)
{
    if(semiMajorAxis == semiMinorAxis)
        return 0; // Bail early if it's a circle
    else if(semiMinorAxis > semiMajorAxis)
    {
        double temp = semiMajorAxis;
        semiMajorAxis = semiMinorAxis;
        semiMinorAxis = temp;
    }
    double focus = findFoci(semiMajorAxis, semiMinorAxis);
    // Implicitly rotate the ellipse, this lets us compute the distance without messing with coordinates
    double vertexToFocus = findDistanceBetweenPoints(focus, 0, 0, semiMinorAxis);
    return focus / vertexToFocus;
}

double findOrbitalPeriod(double semiMajorAxis)
{
    //Tp=Te*(Rp/Re)^3/2
    //Te : Orbital period of Earth //31536000
    //Re : Mean distance between Earth and Sun //1.4960e11m
    //Tp : Orbital period of planet
    //Rp : Mean distance of Planet (Semi Major Axis)
    return 31536000 * pow((semiMajorAxis / 1.4960e11), 1.5);
}

double findTheta(double x, double y){
    if (x==0 && y==0)
        return 0;
	double theta;
	theta = atan(y / x);
	theta = (theta * 180) / PI;
	return theta;
}

double findSemiMinorAxis(double semiMajorAxis, double eccentricity){
    return semiMajorAxis * sqrt (1 - pow(eccentricity,2.0));
}

Vector2D findEllipseAndLineIntersection(double semiMajorAxis, double eccentricity, double theta, double lineXDisplacement, double ellipseXDisplacement, double ellipseYDisplacement)
{
    //Ellipse a = SemiMajorAxis
    //Ellipse b = semiminor
    double lineRate = sin(theta)/cos(theta);
    double semiMinorAxis = findSemiMinorAxis(semiMajorAxis,eccentricity);
    Vector2D point;
    point.x = ((ellipseXDisplacement*pow(semiMinorAxis,2))-(lineRate*(pow(semiMajorAxis,2))*(lineXDisplacement-ellipseYDisplacement))+semiMajorAxis*semiMinorAxis*sqrt(((pow(semiMajorAxis,2))*(pow(lineRate,2)))+pow(semiMinorAxis,2)-pow((lineXDisplacement+lineRate*ellipseXDisplacement),2)-pow(ellipseYDisplacement,2)+(2*(lineXDisplacement+lineRate*ellipseXDisplacement)*ellipseYDisplacement)))/((pow(semiMajorAxis,2))*(pow(lineRate,2))+pow(semiMinorAxis,2));
    point.y = (pow(semiMinorAxis,2)*(lineXDisplacement+lineRate*ellipseXDisplacement))+ellipseYDisplacement*pow(semiMajorAxis,2)*pow(lineRate,2)+semiMajorAxis*semiMinorAxis*lineRate*sqrt(pow(semiMajorAxis,2)*pow(lineRate,2)+pow(semiMinorAxis,2)-pow((lineXDisplacement+lineRate*ellipseXDisplacement),2)-pow(ellipseYDisplacement,2)+(2*(lineXDisplacement+lineRate*ellipseXDisplacement)))/((pow(semiMajorAxis,2)*pow(lineRate,2))+pow(semiMinorAxis,2));
    return point;
}
