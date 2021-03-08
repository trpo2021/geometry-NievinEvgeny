#include "geometry.h"
#include <ctype.h>
#include <stdlib.h>

void SkipSpace(char* str, int* i)
{
    while (isspace(str[*i]))
    {
        *i = *i + 1;
    }
}

int CorrectWritingCircle(char* str, int* i, struct Circle* ArrayOfCircles, int CurrentCircle)
{
    char Circle[] = {"circle"};
    int LengthOfCircle = strlen(Circle);

    SkipSpace(str, i);

    if (strncmp(&str[*i], Circle, LengthOfCircle) != 0)
    {
        return -2;
    }

    *i = *i + LengthOfCircle;

    SkipSpace(str, i);

    if (str[*i] != '(')
    {
        printf("Ошибка в синтаксисе: Ожидается '(' после 'circle'\n");
        return -1;
    }

    *i = *i + 1;
    SkipSpace(str, i);

    char* LetterAfterFirstCoord = &str[*i];
    ArrayOfCircles[CurrentCircle].x = strtod(LetterAfterFirstCoord, &LetterAfterFirstCoord);

    if ((ArrayOfCircles[CurrentCircle].x == 0) && (LetterAfterFirstCoord == &str[*i]))
    {
        printf("Ошибка в синтаксисе: Ожидается координата после '('\n");
        return -1;
    }

    printf("%f\n", ArrayOfCircles[CurrentCircle].x);

    if (*LetterAfterFirstCoord != ' ')
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' после первой координаты\n");
        return -1;
    }

    *i = *i + LetterAfterFirstCoord - &str[*i];
    SkipSpace(str, i);

    char* LetterAfterSecondCoord = &str[*i];
    ArrayOfCircles[CurrentCircle].y = strtod(LetterAfterSecondCoord, &LetterAfterSecondCoord);

    if ((ArrayOfCircles[CurrentCircle].y == 0) && (LetterAfterSecondCoord == &str[*i]))
    {
        printf("Ошибка в синтаксисе: Ожидается вторая координата после первой координаты\n");
        return -1;
    }

    printf("%f\n", ArrayOfCircles[CurrentCircle].y);

    *i = *i + LetterAfterSecondCoord - &str[*i];
    SkipSpace(str, i);

    if (str[*i] != ',')
    {
        printf("Ошибка в синтаксисе: Ожидается ',' после второй координаты\n");
        return -1;
    }

    *i = *i + 1;
    SkipSpace(str, i);

    char* LetterAfterRadius = &str[*i];
    ArrayOfCircles[CurrentCircle].radius = strtod(LetterAfterRadius, &LetterAfterRadius);

    if ((ArrayOfCircles[CurrentCircle].radius == 0) && (LetterAfterRadius == &str[*i]))
    {
        printf("Ошибка в синтаксисе: Ожидается радиус после ','\n");
        return -1;
    }

    if (ArrayOfCircles[CurrentCircle].radius < 0)
    {
        printf("Ошибка: Радиус не может быть отрицательным\n");
        return -1;
    }

    printf("%f\n", ArrayOfCircles[CurrentCircle].radius);

    *i = *i + LetterAfterRadius - &str[*i];
    SkipSpace(str, i);

    if (str[*i] != ')')
    {
        printf("Ошибка в синтаксисе: Ожидается ')' после радиуса\n");
        return -1;
    }

    *i = *i + 1;

    SkipSpace(str, i);

    if (str + *i != str + strlen(str))
    {
        printf("Ошибка в синтаксисе: ожидается 'символ конца строки' после ')'\n");
        return -1;
    }
    else
    {
        printf("Данные введены верно\n");
    }
    *i = 0;
    return 0;
}

int CorrectWritingTriangle(char* str, int* i, struct Triangle* ArrayOfTriangles, int CurrentTriangle)
{
    int NumberOfCoordinatePairs = 4;
    int CurrentCoord = 0;
    char* LetterAfterCoord;
    char Triangle[] = {"triangle"};
    int LengthOfTriangle = strlen(Triangle);

    SkipSpace(str, i);

    if (strncmp(&str[*i], Triangle, LengthOfTriangle) != 0)
    {
        return -2;
    }

    *i = *i + LengthOfTriangle;

    SkipSpace(str, i);

    if (str[*i] != '(')
    {
        printf("Ошибка в синтаксисе: Ожидается '(' после 'triangle'\n");
        return -1;
    }

    *i = *i + 1;
    SkipSpace(str, i);

    while (CurrentCoord < NumberOfCoordinatePairs)
    {
        LetterAfterCoord = &str[*i];
        ArrayOfTriangles[CurrentTriangle].x[CurrentCoord] = strtod(LetterAfterCoord, &LetterAfterCoord);

        if ((ArrayOfTriangles[CurrentTriangle].x[CurrentCoord] == 0) && (LetterAfterCoord == &str[*i]) && (CurrentCoord == 0))
        {
            printf("Ошибка в синтаксисе: Ожидается %d-я X координата после '('\n", CurrentCoord + 1);
            return -1;
        }

        if ((ArrayOfTriangles[CurrentTriangle].x[CurrentCoord] == 0) && (LetterAfterCoord == &str[*i]) && (CurrentCoord != 0))
        {
            printf("Ошибка в синтаксисе: Ожидается %d-я X координата после %d-й ','\n", CurrentCoord + 1, CurrentCoord);
            return -1;
        }

        if (*LetterAfterCoord != ' ')
        {
            printf("Ошибка в синтаксисе: Ожидается ' ' после %d-й X координаты\n", CurrentCoord + 1);
            return -1;
        }

        *i = *i + LetterAfterCoord - &str[*i];
        SkipSpace(str, i);

        printf("%f\n", ArrayOfTriangles[CurrentTriangle].x[CurrentCoord]);

        LetterAfterCoord = &str[*i];
        ArrayOfTriangles[CurrentTriangle].y[CurrentCoord] = strtod(LetterAfterCoord, &LetterAfterCoord);

        if ((ArrayOfTriangles[CurrentTriangle].y[CurrentCoord] == 0) && (LetterAfterCoord == &str[*i]))
        {
            printf("Ошибка в синтаксисе: Ожидается %d-я Y координата после %d-й X координаты\n", CurrentCoord + 1, CurrentCoord + 1);
            return -1;
        }

        *i = *i + LetterAfterCoord - &str[*i];
        SkipSpace(str, i);

        printf("%f\n", ArrayOfTriangles[CurrentTriangle].y[CurrentCoord]);

        if (CurrentCoord < NumberOfCoordinatePairs - 1)
        {
            if (str[*i] != ',')
            {
                printf("Ошибка в синтаксисе: Ожидается ',' после %d-й Y координаты\n", CurrentCoord + 1);
                return -1;
            }
            *i = *i + 1;
        }
        CurrentCoord++;
    }

    if ((ArrayOfTriangles[CurrentTriangle].x[NumberOfCoordinatePairs - 4] != ArrayOfTriangles[CurrentTriangle].x[NumberOfCoordinatePairs - 1])
        || (ArrayOfTriangles[CurrentTriangle].y[NumberOfCoordinatePairs - 4] != ArrayOfTriangles[CurrentTriangle].y[NumberOfCoordinatePairs - 1]))
    {
        printf("Первая координата не соответствует последней -> треугольник не замыкается\n");
        return -1;
    }

    if (str[*i] != ')')
    {
        printf("Ошибка в синтаксисе: Ожидается ')' после последней координаты\n");
        return -1;
    }

    *i = *i + 1;

    SkipSpace(str, i);

    if (str + *i != str + strlen(str))
    {
        printf("Ошибка в синтаксисе: ожидается 'символ конца строки' после ')'\n");
        return -1;
    }
    else
    {
        printf("Данные введены верно\n");
    }
    *i = 0;
    return 0;
}