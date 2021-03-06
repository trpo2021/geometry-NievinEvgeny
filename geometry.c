#include "geometry.h"
#include <stdio.h>

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

        if ((CheckingForCorrectness = CorrectWritingCircle(str, &i, Circles, &NumberOfCurrentCircle)) == -1)
        {
            printf("Ошибка в строке №%d\n", NumberOfCurrentString);
            break;
        }

        PerimeterAndAreaOfACircle(Circles, &NumberOfCurrentCircle);
        printf("%f\n", Circles[NumberOfCurrentCircle].perimeter);
        printf("%f\n", Circles[NumberOfCurrentCircle].area);
        printf("\n");
        NumberOfCurrentString++;
        NumberOfCurrentCircle++;
    }
    printf("Закрытие файла\n");
}