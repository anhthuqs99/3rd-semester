#include <stdio.h>
#include <stdlib.h>

__declspec(dllimport) int __cdecl ia_read(int *arr, int n);

__declspec(dllimport) float __cdecl ia_calc_avg(const int *arr, int n);

__declspec(dllimport) void __cdecl ia_print(const int *arr, int n);

int main(void)
{
    int *arr = NULL;
    int n = 5;
    int rc;

    setbuf(stdout, NULL);

    arr = malloc(sizeof(int) * n);
    if (!arr)
    {
        printf("Memory allocation error.\n");

        return -1;
    }

    rc = ia_read(arr, n);

    if (rc == 0 && n > 0)
    {
        ia_print(arr, n);

        printf("Average of elements: %f\n", ia_calc_avg(arr, n));
    }

    free(arr);

    return rc;
}
