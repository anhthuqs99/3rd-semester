#include <stdio.h>
#include <stdlib.h>
#include "ia_lib.h"

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
