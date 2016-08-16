#include <math.h>

double findDistanceBetweenPoints(double aX, double aY, double bX, double bY) {
    return sqrt(pow((bX - aX), 2) + pow((bY - aY), 2));
}

double findFoci(double semiMajorAxis, double semiMinorAxis) {
    if(semiMinorAxis > semiMajorAxis)
    {
        double temp = semiMajorAxis;
        semiMajorAxis = semiMinorAxis;
        semiMinorAxis = temp;
    }
    return sqrt(pow(semiMajorAxis,2)-pow(semiMinorAxis,2));
}

// eccentricity = distance from the center to a focus Divided by the distance from that focus to a vertex
double findEccentricity(double semiMajorAxis, double semiMinorAxis) {
    if(semiMajorAxis == semiMinorAxis)
        return 0; // Bail early if it's a circle
    else if(semiMinorAxis > semiMajorAxis)
    {
        double temp = semiMajorAxis;
        semiMajorAxis = semiMinorAxis;
        semiMinorAxis = temp;
    }
    double focus = findFoci(semiMajorAxis,semiMinorAxis);
    double vertexToFocus = findDistanceBetweenPoints(focus, 0, 0, semiMinorAxis);
    return focus / vertexToFocus;
}
