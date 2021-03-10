#include "geometry.h"
#include <math.h>

float PerimeterOfACircle(struct Circle Circle)
{
    Circle.perimeter = 2 * M_PI * Circle.radius;
    return Circle.perimeter;
}

float AreaOfACircle(struct Circle Circle)
{
    float Radius = Circle.radius;
    Circle.area = M_PI * pow(Radius, 2);
    return Circle.area;
}

float PerimeterOfATriangle(struct Triangle Triangle)
{
    int NumberOfCoords = 3, i;
    float x[NumberOfCoords];
    float y[NumberOfCoords];
    float side[NumberOfCoords];
    Triangle.perimeter = 0;
    for (i = 0; i < NumberOfCoords; i++)
    {
        x[i] = Triangle.x[i + 1] - Triangle.x[i];
        y[i] = Triangle.y[i + 1] - Triangle.y[i];
        side[i] = sqrt((pow(x[i], 2) + pow(y[i], 2)));
        Triangle.perimeter += side[i];
    }
    return Triangle.perimeter;
}

float AreaOfATriangle(struct Triangle Triangle)
{
    int NumberOfCoords = 3, i;
    float x[NumberOfCoords];
    float y[NumberOfCoords];
    float side[NumberOfCoords];
    float p;
    for (i = 0; i < NumberOfCoords; i++)
    {
        x[i] = Triangle.x[i + 1] - Triangle.x[i];
        y[i] = Triangle.y[i + 1] - Triangle.y[i];
        side[i] = sqrt((pow(x[i], 2) + pow(y[i], 2)));
    }
    p = (side[0] + side[1] + side[2]) / 2;
    Triangle.area = sqrt((p * (p - side[0]) * (p - side[1]) * (p - side[2])));
    return Triangle.area;
}