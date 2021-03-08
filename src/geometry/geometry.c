#include <libgeometry/geometry.h>

int main()
{
    int NumberOfStrings = 10, NumberOfSymbolsInString = 100;
    char str[NumberOfSymbolsInString];
    int i = 0, IsThatATriangle, IsThatACircle;
    int NumberOfCurrentString = 1, NumberOfCurrentCircle = 0, NumberOfCurrentTriangle = 0;
    struct Circle Circles[NumberOfStrings];
    struct Triangle Triangles[NumberOfStrings];

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

        if ((IsThatACircle = CorrectWritingCircle(str, &i, Circles, NumberOfCurrentCircle)) == -1)
        {
            printf("Ошибка в строке №%d\n", NumberOfCurrentString);
            break;
        }

        if (IsThatACircle == 0)
        {
            PerimeterOfACircle(Circles, NumberOfCurrentCircle);
            AreaOfACircle(Circles, NumberOfCurrentCircle);

            printf("Периметр = %f\n", Circles[NumberOfCurrentCircle].perimeter);
            printf("Площадь = %f\n\n", Circles[NumberOfCurrentCircle].area);

            NumberOfCurrentCircle++;
        }

        if ((IsThatATriangle = CorrectWritingTriangle(str, &i, Triangles, NumberOfCurrentTriangle)) == -1)
        {
            printf("Ошибка в строке №%d\n", NumberOfCurrentString);
            break;
        }

        if (IsThatATriangle == 0)
        {
            PerimeterOfATriangle(Triangles, NumberOfCurrentTriangle);
            AreaOfATriangle(Triangles, NumberOfCurrentTriangle);

            if (Triangles[NumberOfCurrentTriangle].area == 0)
            {
                printf("Ошибка: вершины треугольника совпадают или находятся на одной прямой\n");
                break;
            }

            printf("Периметр = %f\n", Triangles[NumberOfCurrentTriangle].perimeter);
            printf("Площадь = %f\n\n", Triangles[NumberOfCurrentTriangle].area);

            NumberOfCurrentTriangle++;
        }

        if ((IsThatACircle == -2) && (IsThatATriangle == -2))
        {
            printf("Ошибка в строке №%d, название фигуры не соответствует 'circle' или 'triangle'\n", NumberOfCurrentString);
            break;
        }

        NumberOfCurrentString++;
    }
    printf("Закрытие файла\n");
    return 0;
}
