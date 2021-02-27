#include <ctype.h>
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

int CorrectWritingCircle(char* str, int* i)
{
    int k = 0;
    char Circle[] = {"circle"};
    int LengthOfCircle = strlen(Circle);
    SkipSpace(str, i);

    if (strncmp(&str[*i], Circle, LengthOfCircle) != 0)
    {
        printf("Ошибка в имени фигуры: Ожидается 'circle'\n");
        return 0;
    }

    *i = *i + LengthOfCircle;
    SkipSpace(str, i);

    if (str[*i] != '(')
    {
        printf("Ошибка в синтаксисе: Ожидается '(' после 'circle'\n");
        return 0;
    }

    *i = *i + 1;
    SkipSpace(str, i);

    char* LetterAfterFirstCoord = &str[*i];
    double x = 0;
    x = strtod(LetterAfterFirstCoord, &LetterAfterFirstCoord);

    if ((x == 0) && (LetterAfterFirstCoord == &str[*i]))
    {
        printf("Ошибка в синтаксисе: Ожидается координата после '('\n");
        return 0;
    }

    printf("%f\n", x);

    if (*LetterAfterFirstCoord != ' ')
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' после первой координаты\n");
        return 0;
    }

    *i = *i + LetterAfterFirstCoord - &str[*i];
    SkipSpace(str, i);

    char* LetterAfterSecondCoord = &str[*i];
    double y = 0;
    y = strtod(LetterAfterSecondCoord, &LetterAfterSecondCoord);

    if ((y == 0) && (LetterAfterSecondCoord == &str[*i]))
    {
        printf("Ошибка в синтаксисе: Ожидается вторая координата после первой координаты\n");
        return 0;
    }

    printf("%f\n", y);

    if ((*LetterAfterSecondCoord != ' ') && (*LetterAfterSecondCoord != ','))
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' или ',' после второй координаты\n");
        return 0;
    }

    *i = *i + LetterAfterSecondCoord - &str[*i];
    SkipSpace(str, i);

    if (str[*i] != ',')
    {
        printf("Ошибка в синтаксисе: Ожидается ',' после второй координаты\n");
        return 0;
    }

    *i = *i + 1;
    SkipSpace(str, i);

    char* LetterAfterRadius = &str[*i];
    double Radius = 0;
    Radius = strtod(LetterAfterRadius, &LetterAfterRadius);

    if ((Radius == 0) && (LetterAfterRadius == &str[*i]))
    {
        printf("Ошибка в синтаксисе: Ожидается радиус после ','\n");
        return 0;
    }

    if (Radius < 0)
    {
        printf("Ошибка: Радиус не может быть отрицательным\n");
        return 0;
    }

    printf("%f\n", Radius);

    if ((*LetterAfterRadius != ' ') && (*LetterAfterRadius != ')'))
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' или ')' после радиуса\n");
        return 0;
    }

    *i = *i + LetterAfterRadius - &str[*i];
    SkipSpace(str, i);

    if (str[*i] != ')')
    {
        printf("Ошибка в синтаксисе: Ожидается ')' после радиуса\n");
        return 0;
    }

    *i = *i + 1;

    SkipSpace(str, i);

    if (str + *i != str + strlen(str))
    {
        printf("Ошибка в синтаксисе: ожидается 'символ конца строки' после ')'\n");
        return 0;
    }
    else
    {
        printf("Данные введены верно\n");
    }
    k++;
    return k;
}

int main()
{
    int N = 50;
    char str[N];
    int i = 0, CheckingForCorrectness = 0;
    char* estr;

    FILE* InputData;
    printf("Открытие файла: ");
    InputData = fopen("input.txt", "r");
    if (InputData == NULL)
    {
        printf("ошибка\n");
        return 0;
    }
    else
    {
        printf("выполнено\n");
    }
    printf("Считаны строки:\n");

    // int CoordXForCircles[N];
    // int CoordYForCircles[N];
    // int RadiusesOfCircles[N];

    //----------------Заготовка на несколько строк---------------
    // int F;
    // int j = 0;
    // printf("Сколько фигур?");
    // scanf("%d", &F);
    // char str[N][F]
    // for (j = 0; j < F; j++)
    //{
    //  fgets(str[j], N, stdin);
    //}
    //-----------------------------------------------------------

    fgets(str, N, InputData);
    if ((CheckingForCorrectness = CorrectWritingCircle(str, &i)) == 0)
    {
        return 0;
    }
}