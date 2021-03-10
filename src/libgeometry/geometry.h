#pragma once
#include <stdio.h>

struct Circle
{
    float x;
    float y;
    float radius;
    float perimeter;
    float area;
};

struct Triangle
{
    float x[4];
    float y[4];
    float perimeter;
    float area;
};

void FindASides(struct Triangle Triangle, float* side);

float PerimeterOfACircle(struct Circle Circle);

float AreaOfACircle(struct Circle Circle);

float PerimeterOfATriangle(struct Triangle Triangle);

float AreaOfATriangle(struct Triangle Triangle);

int CorrectWritingCircle(char* str, int* i, struct Circle* ArrayOfCircles, int CurrentCircle);

int CorrectWritingTriangle(char* str, int* i, struct Triangle* ArrayOfTriangles, int CurrentTriangle);
