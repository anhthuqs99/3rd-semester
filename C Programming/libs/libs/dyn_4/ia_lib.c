#include <assert.h>
#include <stdio.h>
#include "ia_lib.h"

IA_DLL int IA_DECL ia_read(int *arr, int n)
{
    printf("Input %d integers:\n", n);

    for (int i = 0; i < n; i++)
        if (scanf("%d", arr + i) != 1)
            return -1;

    return 0;
}

IA_DLL float IA_DECL ia_calc_avg(const int *arr, int n)
{
    assert(n);

    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    return ((float) sum) / n;
}

IA_DLL void IA_DECL ia_print(const int *arr, int n)
{
    printf("Array:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

IA_DLL int IA_DECL ia_filter_pos(const int *src_arr, int src_n, int *dst_arr, int *dst_n)
{
    assert(dst_n);

    int n = 0;

    // Поймем массив какого размера нам требуется
    for (int i = 0; i < src_n; i++)
        if (src_arr[i] > 0)
            n++;

    if (n > *dst_n)
    {
        // Массив, который передали, слишком маленький

        *dst_n = n;

        return -1;
    }

    n = 0;
    for (int i = 0; i < src_n; i++)
        if (src_arr[i] > 0)
            dst_arr[n++] = src_arr[i];

    *dst_n = n;

    return 0;
}
