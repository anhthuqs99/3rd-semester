#include <stdio.h>
#include "io.h"

void input_values(time_range *T1, time_range *T2, time_range *T3, time_range *T4)
{
    int flag = 1;
    if (flag)
    {
        input_range(T1, 1);
        input_range(T2, 2);
        input_range(T3, 3);
        input_range(T4, 4);
    }
}

void input_range(time_range *T, int i)
{
    int done = 0;
    while (!done)
    {
        done = 1;
        printf("\nInput T%d_min T%d_max  value: ", i, i);
        fflush(stdin);
        if (scanf("%lf %lf", &(T->min), &(T->max)) != 2)
            done = 0;
        if (T->min < 0 || T->max < 0)
        {
            done = 0;
            printf("Must be positive nunber!\n");
        }
        if (T->min > T->max)
        {
            done = 0;
            printf("Error range!\n");
        }
        if (!done)
            printf("Invailid input\n");
    }
}

void print_values(int n, int interval, int log, time_range *T1, time_range *T2, time_range *T3, time_range *T4)
{
    /*
    printf("Stop queue1_out value is %d\n", n);

    if (log)
        printf("Show log every %d queue1_out\n", interval);
    else
        printf("Don't show log.\n");
    */
    print_range(T1, 1);
    print_range(T2, 2);
    print_range(T3, 3);
    print_range(T4, 4);
}

void print_range(time_range *T, int i)
{
    printf("T%d_min: %lf   T%d_max: %lf \n", i, T->min, i, T->max);
}
