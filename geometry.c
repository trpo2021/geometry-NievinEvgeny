#include "geometry.h"

int main()
{
    int NumberOfStrings = 10, NumberOfSymbolsInString = 100;
    char str[NumberOfSymbolsInString];
    int i = 0, CheckingForCorrectness = 0;
    int NumberOfCurrentString = 1, NumberOfCurrentCircle = 0, NumberOfCurrentTriangle = 0;
    char* estr;
    struct Circle Circles[NumberOfStrings];
    struct Triangle Triangles[NumberOfStrings];
    char Triangle[] = {"triangle"};
    int LengthOfTriangle = strlen(Triangle);
    char Circle[] = {"circle"};
    int LengthOfCircle = strlen(Circle);

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

        estr = fgets(str, NumberOfSymbolsInString, InputData);
        if (estr == NULL)
        {
            break;
        }

        SkipSpace(estr, &i);

        if (strncmp(estr, Circle, LengthOfCircle) == 0)
        {
            if ((CheckingForCorrectness = CorrectWritingCircle(str, &i, Circles, &NumberOfCurrentCircle)) == -1)
            {
                printf("Ошибка в строке №%d\n", NumberOfCurrentString);
                break;
            }
            PerimeterAndAreaOfACircle(Circles, &NumberOfCurrentCircle);
            printf("%f\n", Circles[NumberOfCurrentCircle].perimeter);
            printf("%f\n\n", Circles[NumberOfCurrentCircle].area);
            NumberOfCurrentCircle++;
        }

        if (strncmp(estr, Triangle, LengthOfTriangle) == 0)
        {
            if ((CheckingForCorrectness = CorrectWritingTriangle(str, &i, Triangles, &NumberOfCurrentTriangle)) == -1)
            {
                printf("Ошибка в строке №%d\n", NumberOfCurrentString);
                break;
            }
            NumberOfCurrentTriangle++;
        }

        NumberOfCurrentString++;
    }
    printf("Закрытие файла\n");
    return 0;
}