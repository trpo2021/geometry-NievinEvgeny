#pragma once
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SkipSpace(char* str, int* i);

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

void PerimeterAndAreaOfACircle(struct Circle* ArrayOfCircles, int* CurrentCircle);

void PerimeterAndAreaOfATriangle(struct Triangle* ArrayOfTriangles, int* CurrentTriangle);

int CorrectWritingCircle(char* str, int* i, struct Circle* ArrayOfCircles, int* CurrentCircle);

int CorrectWritingTriangle(char* str, int* i, struct Triangle* ArrayOfTriangles, int* CurrentTriangle);
