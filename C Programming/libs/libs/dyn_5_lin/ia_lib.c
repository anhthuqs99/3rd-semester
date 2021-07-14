#include <assert.h>
#include <stdio.h>
#include "ia_lib.h"

int ia_read(int *arr, int n)
{
    printf("Input %d integers:\n", n);

    for (int i = 0; i < n; i++)
        if (scanf("%d", arr + i) != 1)
            return -1;

    return 0;
}

float ia_calc_avg(const int *arr, int n)
{
    assert(n);

    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return ((float) sum) / n;
}

void ia_print(const int *arr, int n)
{
    printf("Array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
