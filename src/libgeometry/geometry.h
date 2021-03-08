#pragma once
#include <stdio.h>
#include <string.h>

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

void PerimeterOfACircle(struct Circle* ArrayOfCircles, int CurrentCircle);

void AreaOfACircle(struct Circle* ArrayOfCircles, int CurrentCircle);

void PerimeterOfATriangle(struct Triangle* ArrayOfTriangles, int CurrentTriangle);

void AreaOfATriangle(struct Triangle* ArrayOfTriangles, int CurrentTriangle);

void SkipSpace(char* str, int* i);

int CorrectWritingCircle(char* str, int* i, struct Circle* ArrayOfCircles, int CurrentCircle);

int CorrectWritingTriangle(char* str, int* i, struct Triangle* ArrayOfTriangles, int CurrentTriangle);
