#include "geometry.h"
#include <math.h>

void PerimeterAndAreaOfACircle(struct Circle* ArrayOfCircles, int* CurrentCircle)
{
    float Radius = ArrayOfCircles[*CurrentCircle].radius;
    ArrayOfCircles[*CurrentCircle].perimeter = 2 * M_PI * ArrayOfCircles[*CurrentCircle].radius;
    ArrayOfCircles[*CurrentCircle].area = M_PI * pow(Radius, 2);
}

void PerimeterAndAreaOfATriangle(struct Triangle* ArrayOfTriangles, int* CurrentTriangle)
{
    float x1, x2, x3, y1, y2, y3, p, AB, BC, AC;
    x1 = ArrayOfTriangles[*CurrentTriangle].x[1] - ArrayOfTriangles[*CurrentTriangle].x[0];
    x2 = ArrayOfTriangles[*CurrentTriangle].x[2] - ArrayOfTriangles[*CurrentTriangle].x[1];
    x3 = ArrayOfTriangles[*CurrentTriangle].x[0] - ArrayOfTriangles[*CurrentTriangle].x[2];
    y1 = ArrayOfTriangles[*CurrentTriangle].y[1] - ArrayOfTriangles[*CurrentTriangle].y[0];
    y2 = ArrayOfTriangles[*CurrentTriangle].y[2] - ArrayOfTriangles[*CurrentTriangle].y[1];
    y3 = ArrayOfTriangles[*CurrentTriangle].y[0] - ArrayOfTriangles[*CurrentTriangle].y[2];
    AB = sqrt((pow(x1, 2) + pow(y1, 2)));
    BC = sqrt((pow(x2, 2) + pow(y2, 2)));
    AC = sqrt((pow(x3, 2) + pow(y3, 2)));
    ArrayOfTriangles[*CurrentTriangle].perimeter = AB + BC + AC;
    p = (AB + BC + AC) / 2;
    ArrayOfTriangles[*CurrentTriangle].area = sqrt((p * (p - AB) * (p - BC) * (p - AC)));
}