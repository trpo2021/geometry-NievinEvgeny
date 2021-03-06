#include "geometry.h"

int main()
{
    int NumberOfStrings = 10, NumberOfSymbolsInString = 100;
    char str[NumberOfSymbolsInString];
    int i = 0;
    int NumberOfCurrentString = 1, NumberOfCurrentCircle = 0, NumberOfCurrentTriangle = 0;
    struct Circle Circles[NumberOfStrings];
    char Circle[] = {"circle"};
    int LengthOfCircle = strlen(Circle);
    struct Triangle Triangles[NumberOfStrings];
    char Triangle[] = {"triangle"};
    int LengthOfTriangle = strlen(Triangle);

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
        printf("выполнено\n\n");
    }

    while (1)
    {
        if (NumberOfCurrentString == NumberOfStrings)
        {
            printf("Превышено количество строк, максимум: %d\n", NumberOfStrings);
            break;
        }

        if (fgets(str, NumberOfSymbolsInString, InputData) == NULL)
        {
            break;
        }

        SkipSpace(str, &i);

        if (strncmp(&str[i], Circle, LengthOfCircle) == 0)
        {
            i = i + LengthOfCircle;
            if (CorrectWritingCircle(str, &i, Circles, &NumberOfCurrentCircle) == -1)
            {
                i = 0;
                printf("Ошибка в строке №%d\n", NumberOfCurrentString);
                break;
            }
            PerimeterAndAreaOfACircle(Circles, &NumberOfCurrentCircle);
            printf("%f\n", Circles[NumberOfCurrentCircle].perimeter);
            printf("%f\n\n", Circles[NumberOfCurrentCircle].area);
            NumberOfCurrentCircle++;
        }

        if (strncmp(&str[i], Triangle, LengthOfTriangle) == 0)
        {
            i = i + LengthOfTriangle;
            if (CorrectWritingTriangle(str, &i, Triangles, &NumberOfCurrentTriangle) == -1)
            {
                i = 0;
                printf("Ошибка в строке №%d\n", NumberOfCurrentString);
                break;
            }
        }
        NumberOfCurrentString++;
    }
    printf("Закрытие файла\n");
    return 0;
}
