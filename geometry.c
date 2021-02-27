#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SkipSpace(char* str, int* i)
{
    while (isspace(str[*i]))
    {
        *i = *i + 1;
    }
}

struct Circle
{
    float x;
    float y;
    float radius;
    float perimeter;
    float area;
};

void PerimeterAndAreaOfACircle(struct Circle* ArrayOfCircles, int* CurrentCircle)
{
    float Radius = ArrayOfCircles[*CurrentCircle].radius;
    ArrayOfCircles[*CurrentCircle].perimeter = 2 * M_PI * ArrayOfCircles[*CurrentCircle].radius;
    ArrayOfCircles[*CurrentCircle].perimeter = M_PI * pow(Radius, 2);
}

int CorrectWritingCircle(char* str, int* i, struct Circle* ArrayOfCircles, int* CurrentCircle)
{
    char Circle[] = {"circle"};
    int LengthOfCircle = strlen(Circle);
    SkipSpace(str, i);

    if (strncmp(&str[*i], Circle, LengthOfCircle) != 0)
    {
        printf("Ошибка в имени фигуры: Ожидается 'circle'\n");
        return -1;
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
    ArrayOfCircles[*CurrentCircle].x = strtod(LetterAfterFirstCoord, &LetterAfterFirstCoord);

    if ((ArrayOfCircles[*CurrentCircle].x == 0) && (LetterAfterFirstCoord == &str[*i]))
    {
        printf("Ошибка в синтаксисе: Ожидается координата после '('\n");
        return -1;
    }

    printf("%f\n", ArrayOfCircles[*CurrentCircle].x);

    if (*LetterAfterFirstCoord != ' ')
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' после первой координаты\n");
        return -1;
    }

    *i = *i + LetterAfterFirstCoord - &str[*i];
    SkipSpace(str, i);

    char* LetterAfterSecondCoord = &str[*i];
    ArrayOfCircles[*CurrentCircle].y = strtod(LetterAfterSecondCoord, &LetterAfterSecondCoord);

    if ((ArrayOfCircles[*CurrentCircle].y == 0) && (LetterAfterSecondCoord == &str[*i]))
    {
        printf("Ошибка в синтаксисе: Ожидается вторая координата после первой координаты\n");
        return -1;
    }

    printf("%f\n", ArrayOfCircles[*CurrentCircle].y);

    if ((*LetterAfterSecondCoord != ' ') && (*LetterAfterSecondCoord != ','))
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' или ',' после второй координаты\n");
        return -1;
    }

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
    ArrayOfCircles[*CurrentCircle].radius = strtod(LetterAfterRadius, &LetterAfterRadius);

    if ((ArrayOfCircles[*CurrentCircle].radius == 0) && (LetterAfterRadius == &str[*i]))
    {
        printf("Ошибка в синтаксисе: Ожидается радиус после ','\n");
        return -1;
    }

    if (ArrayOfCircles[*CurrentCircle].radius < 0)
    {
        printf("Ошибка: Радиус не может быть отрицательным\n");
        return -1;
    }

    printf("%f\n", ArrayOfCircles[*CurrentCircle].radius);

    if ((*LetterAfterRadius != ' ') && (*LetterAfterRadius != ')'))
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' или ')' после радиуса\n");
        return -1;
    }

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
        printf("Данные введены верно, переход к новой строке...\n");
    }
    *i = 0;
    return 0;
}

int main()
{
    int NumberOfSymbolsInString = 50;
    int NumberOfStrings = 10;
    char str[NumberOfSymbolsInString];
    int i = 0, CheckingForCorrectness = 0;
    int NumberOfCurrentString = 1, NumberOfCurrentCircle = 0;
    char* estr;
    struct Circle Circles[NumberOfStrings];

    FILE* InputData;
    printf("Открытие файла: ");
    InputData = fopen("input.txt", "r");
    if (InputData == NULL)
    {
        printf("ошибка\n");
        return -1;
    }
    else
    {
        printf("выполнено\n");
    }

    while (1)
    {
        if (NumberOfCurrentString == NumberOfStrings)
        {
            printf("Превышено количество строк, максимум: %d\n", NumberOfStrings);
            break;
        }

        estr = fgets(str, NumberOfSymbolsInString, InputData);
        if (estr == NULL)
        {
            break;
        }

        if ((CheckingForCorrectness = CorrectWritingCircle(str, &i, Circles, &NumberOfCurrentCircle)) == -1)
        {
            printf("Ошибка в строке №%d\n", NumberOfCurrentString);
            break;
        }

        NumberOfCurrentString++;
        NumberOfCurrentCircle++;
    }
    printf("Закрытие файла\n");
}