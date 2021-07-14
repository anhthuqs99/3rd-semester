#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

// ���� ������� �������������� �� SO
typedef int (*fn_read_t)(int*, int);
typedef float (*fn_calc_avg_t)(const int*, int);
typedef void (*fn_print_t)(const int*, int);

int main(void)
{
    void *hlib;
    fn_read_t ia_read;
    fn_calc_avg_t ia_calc_avg;
    fn_print_t ia_print;
    int *arr;
    int n = 5;
    int rc = 0;

    setbuf(stdout, NULL);

    // �������� ������������ ����������
    hlib = dlopen("ia.so", RTLD_LAZY);
    if (!hlib)
    {
        printf("Cannot open library (%s).\n", dlerror());

        rc = -1;

        goto out;
    }

    // ����������� ����� (?), �� �������� ��������� ����������
    printf("Library is loaded at address %p.\n", (void*) hlib);

    arr = malloc(sizeof(int) * n);
    if (!arr)
    {
        printf("Memory allocation error.\n");

        rc = -2;

        goto free_lib;
    }

    // ������� ����� ������� "ia_read"
    ia_read = (fn_read_t) dlsym(hlib, "ia_read");
    if (!ia_read)
    {
        printf("Can not load function (%s).\n", dlerror());

        rc = -3;

        goto free_mem;
    }

    // ����������� ����� ������� "ia_read"
    printf("ia_read function is located at address %p.\n", (void*) ia_read);

    // ������� ����� ������� "ia_calc_avg"
    ia_calc_avg = (fn_calc_avg_t) dlsym(hlib, "ia_calc_avg");
    if (!ia_calc_avg)
    {
        printf("Can not load function (%s).\n", dlerror());

        rc = -3;

        goto free_mem;
    }

    // ����������� ����� ������� "ia_calc_avg"
    printf("ia_calc_avg function is located at address %p.\n", (void*) ia_calc_avg);

    // ������� ����� ������� "ia_print"
    ia_print = (fn_print_t) dlsym(hlib, "ia_print");
    if (!ia_print)
    {
        printf("Can not load function (%s).\n", dlerror());

        rc = -3;

        goto free_mem;
    }

    // ����������� ����� ������� "ia_print"
    printf("ia_print function is located at address %p.\n", (void*) ia_print);

    rc = ia_read(arr, n);

    if (rc == 0 && n > 0)
    {
        ia_print(arr, n);

        printf("Average of elements: %f\n", ia_calc_avg(arr, n));
    }

free_mem:
    free(arr);

free_lib:
    dlclose(hlib);

out:
    return rc;
}
