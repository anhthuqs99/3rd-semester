#include <stdio.h>
#include <strings.h>
#include "input.h"


int input_flag(char *msg)
{
    int flag = 0;
    char c;
    printf("%s", msg);

    do
    {
        fflush(stdin);
        printf("[y/n]: ");
        scanf("%c", &c);

        if (c == 'y' || c == 'Y')
            flag = 2;
        else if (c == 'n' || c == 'N')
            flag = 1;
    }
    while (!flag);

    return flag-1;
}

void input_size(char *msg, int *n, int *m)
{
    printf("%s", msg);
    fflush(stdin);
    int OK = 0;

    while (!OK)
    {
        OK = 1;
        if (scanf("%d%d", n, m) != 2)
            OK = 0;
        if (OK && (*n <= 0 || *m <= 0))
            OK = 0;
        if (!OK)
            printf("Input ERR. Try again: ");
        fflush(stdin);
    }
}
