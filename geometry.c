#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double strtod(const char* string, char** endptr);

int main()
{
    char str[50];
    int i = 0;
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
    while (str[i] == ' ') {
        i++;
    }

    if (((str[i] == 'c') || (str[i] == 'C'))
        && ((str[i + 1] == 'i') || (str[i + 1] == 'I'))
        && ((str[i + 2] == 'R') || (str[i + 2] == 'r'))
        && ((str[i + 3] == 'c') || (str[i + 3] == 'C'))
        && ((str[i + 4] == 'l') || (str[i + 4] == 'L'))
        && ((str[i + 5] == 'e') || (str[i + 5] == 'E'))) {
        i = i + 6;
        while (str[i] == ' ') {
            i++;
        }
        if (str[i] == '(') {
            i++;
            while (str[i] == ' ') {
                i++;
            }

            if (isdigit(str[i])) {
                char* strtodhelper1 = &str[i];
                double x = 0;
                x = strtod(strtodhelper1, &strtodhelper1);
                printf("%f\n", x);

                if (*strtodhelper1 != ' ') {
                    printf("Ошибка в синтаксисе: Ожидается ' ' после первой "
                           "координаты\n");
                } else {
                    while (str[i] != ' ') {
                        i++;
                    }
                    while (str[i] == ' ') {
                        i++;
                    }
                    if (isdigit(str[i])) {
                        char* strtodhelper2 = &str[i];
                        double y = 0;
                        y = strtod(strtodhelper2, &strtodhelper2);
                        printf("%f\n", y);

                        if ((*strtodhelper2 != ' ')
                            && (*strtodhelper2 != ',')) {
                            printf("Ошибка в синтаксисе: Ожидается ' ' или ',' "
                                   "после второй координаты\n");
                        } else {
                            while ((str[i] != ' ') && (str[i] != ',')) {
                                i++;
                            }
                            while (str[i] == ' ') {
                                i++;
                            }
                            if (str[i] != ',') {
                                printf("Ошибка в синтаксисе: Ожидается ',' "
                                       "после второй координаты\n");
                            } else {
                                i++;
                                while (str[i] == ' ') {
                                    i++;
                                }
                                if (isdigit(str[i])) {
                                    char* strtodhelper3 = &str[i];
                                    double radius = 0;
                                    radius = strtod(
                                            strtodhelper3, &strtodhelper3);
                                    printf("%f\n", radius);

                                    if ((*strtodhelper3 != ' ')
                                        && (*strtodhelper3 != ')')) {
                                        printf("Ошибка в синтаксисе: Ожидается "
                                               "' ' или ')' после радиуса\n");
                                    } else {
                                        while ((str[i] != ' ')
                                               && (str[i] != ')')) {
                                            i++;
                                        }
                                        while (str[i] == ' ') {
                                            i++;
                                        }
                                        if (str[i] != ')') {
                                            printf("Ошибка в синтаксисе: "
                                                   "Ожидается ')' после "
                                                   "радиуса\n");
                                        } else {
                                            i++;
                                            if (str[i] == '\n') {
                                                printf("Данные введены "
                                                       "верно\n");
                                            } else {
                                                if (str[i] == ' ') {
                                                    while (str[i] == ' ') {
                                                        i++;
                                                    }
                                                    if (str[i] == '\n') {
                                                        printf("Данные введены "
                                                               "верно\n");
                                                    } else {
                                                        printf("Ошибка в "
                                                               "синтаксисе: "
                                                               "Ожидается "
                                                               "'символ конца "
                                                               "строки' после "
                                                               "')'\n");
                                                    }
                                                } else {
                                                    printf("Ошибка в "
                                                           "синтаксисе: "
                                                           "Ожидается 'символ "
                                                           "конца строки' "
                                                           "после ')'\n");
                                                }
                                            }
                                        }
                                    }
                                } else {
                                    printf("Ошибка в синтаксисе: Ожидается "
                                           "радиус после ','\n");
                                }
                            }
                        }
                    } else {
                        printf("Ошибка в синтаксисе: Ожидается вторая "
                               "координата после первой координаты\n");
                    }
                }
            } else {
                printf("Ошибка в синтаксисе: Ожидается координата после '('\n");
            }
        } else {
            printf("Ошибка в синтаксисе: Ожидается '(' после 'circle'\n");
        }
    } else {
        printf("Ошибка в имени фигуры: Ожидается 'circle'\n");
    }
}