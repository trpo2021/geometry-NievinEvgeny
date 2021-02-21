#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SkipUntilSpaceOrBracket(char* str, int* i)
{
    while ((isspace(str[*i]) == 0) && (str[*i] != ')'))
    {
        *i = *i + 1;
    }
}

void SkipUntilSpaceOrComma(char* str, int* i)
{
    while ((isspace(str[*i]) == 0) && (str[*i] != ','))
    {
        *i = *i + 1;
    }
}

void SkipUntilSpace(char* str, int* i)
{
    while (isspace(str[*i]) == 0)
    {
        *i = *i + 1;
    }
}

void SkipTheSpace(char* str, int* i)
{
    while (isspace(str[*i]))
    {
        *i = *i + 1;
    }
}

void SkipTheSpaceUntilNewLine(char* str, int* i)
{
    while ((isspace(str[*i])) && (str[*i] != '\n'))
    {
        *i = *i + 1;
    }
}

int main()
{
    char str[50];
    int i = 0;
    char circle[] = {'c', 'i', 'r', 'c', 'l', 'e'};

    //----------------Заготовка на несколько строк---------------
    // int N;
    // int j = 0;
    // printf("Сколько фигур?");
    // scanf("%d", &N);
    // char str[50][N]
    // for (j = 0; j < N; j++)
    //{
    //  fgets(str[j], 50, stdin);
    //}
    //-----------------------------------------------------------

    fgets(str, 50, stdin);

    SkipTheSpace(str, &i);

    if (strncmp(&str[i], circle, 6) != 0)
    {
        printf("Ошибка в имени фигуры: Ожидается 'circle'\n");
        return 0;
    }

    i = i + 6;
    SkipTheSpace(str, &i);

    if (str[i] != '(')
    {
        printf("Ошибка в синтаксисе: Ожидается '(' после 'circle'\n");
        return 0;
    }

    i++;
    SkipTheSpace(str, &i);

    if (isdigit(str[i]) == 0)
    {
        printf("Ошибка в синтаксисе: Ожидается координата после '('\n");
        return 0;
    }

    char* strtodhelper1 = &str[i];
    double x = 0;
    x = strtod(strtodhelper1, &strtodhelper1);
    printf("%f\n", x);

    if (*strtodhelper1 != ' ')
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' после первой координаты\n");
        return 0;
    }

    SkipUntilSpace(str, &i);
    SkipTheSpace(str, &i);

    if (isdigit(str[i]) == 0)
    {
        printf("Ошибка в синтаксисе: Ожидается вторая координата после первой координаты\n");
        return 0;
    }

    char* strtodhelper2 = &str[i];
    double y = 0;
    y = strtod(strtodhelper2, &strtodhelper2);
    printf("%f\n", y);

    if ((*strtodhelper2 != ' ') && (*strtodhelper2 != ','))
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' или ',' после второй координаты\n");
        return 0;
    }

    SkipUntilSpaceOrComma(str, &i);
    SkipTheSpace(str, &i);

    if (str[i] != ',')
    {
        printf("Ошибка в синтаксисе: Ожидается ',' после второй координаты\n");
        return 0;
    }

    i++;
    SkipTheSpace(str, &i);

    if (isdigit(str[i]) == 0)
    {
        printf("Ошибка в синтаксисе: Ожидается радиус после ','\n");
        return 0;
    }

    char* strtodhelper3 = &str[i];
    double radius = 0;
    radius = strtod(strtodhelper3, &strtodhelper3);
    printf("%f\n", radius);

    if ((*strtodhelper3 != ' ') && (*strtodhelper3 != ')'))
    {
        printf("Ошибка в синтаксисе: Ожидается ' ' или ')' после радиуса\n");
        return 0;
    }

    SkipUntilSpaceOrBracket(str, &i);
    SkipTheSpace(str, &i);

    if (str[i] != ')')
    {
        printf("Ошибка в синтаксисе: Ожидается ')' после радиуса\n");
        return 0;
    }

    i++;

    if (str[i] == '\n')
    {
        printf("Данные введены верно\n");
        return 0;
    }

    if (isspace(str[i]) == 0)
    {
        printf("Ошибка в синтаксисе: Ожидается 'символ конца строки' после ')'\n");
        return 0;
    }

    SkipTheSpaceUntilNewLine(str, &i);

    if (str[i] != '\n')
    {
        printf("Ошибка в синтаксисе: Ожидается 'символ конца строки' после ')'\n");
        return 0;
    }
    else
    {
        printf("Данные введены верно\n");
        return 0;
    }
}