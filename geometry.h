#pragma once

void SkipSpace(char* str, int* i);

struct Circle
{
    float x;
    float y;
    float radius;
    float perimeter;
    float area;
};

void PerimeterAndAreaOfACircle(struct Circle* ArrayOfCircles, int* CurrentCircle);

int CorrectWritingCircle(char* str, int* i, struct Circle* ArrayOfCircles, int* CurrentCircle);
