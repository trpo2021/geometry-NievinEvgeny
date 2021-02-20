#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void skipthespace(char* str, int* i)
{
    while (isspace(str[*i]))
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

    skipthespace(str, &i);

    if (strncmp(&str[i], circle, 6) == 0)
    {
        i = i + 6;
        skipthespace(str, &i);
        if (str[i] == '(')
        {
            i++;
            skipthespace(str, &i);

            if (isdigit(str[i]))
            {
                char* strtodhelper1 = &str[i];
                double x = 0;
                x = strtod(strtodhelper1, &strtodhelper1);
                printf("%f\n", x);

                if (*strtodhelper1 != ' ')
                {
                    printf("Ошибка в синтаксисе: Ожидается ' ' после первой координаты\n");
                }
                else
                {
                    while (str[i] != ' ')
                    {
                        i++;
                    }
                    skipthespace(str, &i);
                    if (isdigit(str[i]))
                    {
                        char* strtodhelper2 = &str[i];
                        double y = 0;
                        y = strtod(strtodhelper2, &strtodhelper2);
                        printf("%f\n", y);

                        if ((*strtodhelper2 != ' ') && (*strtodhelper2 != ','))
                        {
                            printf("Ошибка в синтаксисе: Ожидается ' ' или ',' после второй координаты\n");
                        }
                        else
                        {
                            while ((str[i] != ' ') && (str[i] != ','))
                            {
                                i++;
                            }
                            skipthespace(str, &i);
                            if (str[i] != ',')
                            {
                                printf("Ошибка в синтаксисе: Ожидается ',' после второй координаты\n");
                            }
                            else
                            {
                                i++;
                                skipthespace(str, &i);
                                if (isdigit(str[i]))
                                {
                                    char* strtodhelper3 = &str[i];
                                    double radius = 0;
                                    radius = strtod(strtodhelper3, &strtodhelper3);
                                    printf("%f\n", radius);

                                    if ((*strtodhelper3 != ' ') && (*strtodhelper3 != ')'))
                                    {
                                        printf("Ошибка в синтаксисе: Ожидается ' ' или ')' после радиуса\n");
                                    }
                                    else
                                    {
                                        while ((str[i] != ' ') && (str[i] != ')'))
                                        {
                                            i++;
                                        }
                                        skipthespace(str, &i);
                                        if (str[i] != ')')
                                        {
                                            printf("Ошибка в синтаксисе: Ожидается ')' после радиуса\n");
                                        }
                                        else
                                        {
                                            i++;
                                            if (str[i] == '\n')
                                            {
                                                printf("Данные введены верно\n");
                                            }
                                            else
                                            {
                                                if (str[i] == ' ')
                                                {
                                                    skipthespace(str, &i);
                                                    if (str[i] == '\n')
                                                    {
                                                        printf("Данные введены верно\n");
                                                    }
                                                    else
                                                    {
                                                        printf("Ошибка в синтаксисе: Ожидается 'символ конца строки' после ')'\n");
                                                    }
                                                }
                                                else
                                                {
                                                    printf("Ошибка в синтаксисе: Ожидается 'символ конца строки' после ')'\n");
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    printf("Ошибка в синтаксисе: Ожидается радиус после ','\n");
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("Ошибка в синтаксисе: Ожидается вторая координата после первой координаты\n");
                    }
                }
            }
            else
            {
                printf("Ошибка в синтаксисе: Ожидается координата после '('\n");
            }
        }
        else
        {
            printf("Ошибка в синтаксисе: Ожидается '(' после 'circle'\n");
        }
    }
    else
    {
        printf("Ошибка в имени фигуры: Ожидается 'circle'\n");
    }
}