#include "geometry.h"
#include <math.h>

void PerimeterOfACircle(struct Circle* ArrayOfCircles, int CurrentCircle)
{
    ArrayOfCircles[CurrentCircle].perimeter = 2 * M_PI * ArrayOfCircles[CurrentCircle].radius;
}

void AreaOfACircle(struct Circle* ArrayOfCircles, int CurrentCircle)
{
    float Radius = ArrayOfCircles[CurrentCircle].radius;
    ArrayOfCircles[CurrentCircle].area = M_PI * pow(Radius, 2);
}

void PerimeterOfATriangle(struct Triangle* ArrayOfTriangles, int CurrentTriangle)
{
    int NumberOfCoords = 3, i;
    float x[NumberOfCoords];
    float y[NumberOfCoords];
    float side[NumberOfCoords];
    ArrayOfTriangles[CurrentTriangle].perimeter = 0;
    for (i = 0; i < NumberOfCoords; i++)
    {
        x[i] = ArrayOfTriangles[CurrentTriangle].x[i + 1] - ArrayOfTriangles[CurrentTriangle].x[i];
        y[i] = ArrayOfTriangles[CurrentTriangle].y[i + 1] - ArrayOfTriangles[CurrentTriangle].y[i];
        side[i] = sqrt((pow(x[i], 2) + pow(y[i], 2)));
        ArrayOfTriangles[CurrentTriangle].perimeter += side[i];
    }
}

void AreaOfATriangle(struct Triangle* ArrayOfTriangles, int CurrentTriangle)
{
    int NumberOfCoords = 3, i;
    float x[NumberOfCoords];
    float y[NumberOfCoords];
    float side[NumberOfCoords];
    float p;
    for (i = 0; i < NumberOfCoords; i++)
    {
        x[i] = ArrayOfTriangles[CurrentTriangle].x[i + 1] - ArrayOfTriangles[CurrentTriangle].x[i];
        y[i] = ArrayOfTriangles[CurrentTriangle].y[i + 1] - ArrayOfTriangles[CurrentTriangle].y[i];
        side[i] = sqrt((pow(x[i], 2) + pow(y[i], 2)));
    }
    p = (side[0] + side[1] + side[2]) / 2;
    ArrayOfTriangles[CurrentTriangle].area = sqrt((p * (p - side[0]) * (p - side[1]) * (p - side[2])));
}