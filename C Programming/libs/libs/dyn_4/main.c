#include <stdio.h>
#include <stdlib.h>
#include "ia_lib.h"

int main(void)
{
    int *arr = NULL, *arr_pos = NULL;
    int n = 5, n_pos = 0;
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

        rc = ia_filter_pos(arr, n, arr_pos, &n_pos);

        if (rc == -1 && n_pos > 0)
        {
            arr_pos = malloc(n_pos * sizeof(int));
			
            if (arr_pos)
                rc = ia_filter_pos(arr, n, arr_pos, &n_pos);
        }
		
        ia_print(arr_pos, n_pos);
		
        free(arr_pos);
    }

    free(arr);

    return rc;
}
