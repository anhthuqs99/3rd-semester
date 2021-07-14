#include <stdio.h>
#include <stdlib.h>
#include "time_testing.h"
#include "alloc.h"
#include <time.h>
#include "matrices.h"

#define ITER 3
#define ITER_2 3

unsigned long long tick(void)
{
    unsigned long long tmp;
    __asm__ __volatile__ ("rdtsc" : "=A" (tmp) );
    return tmp;
}

void time_testing(int n, int m, int fill)
{
    unsigned long long time_b, time_e, time1, time2;

    int *matr1, *matr2, *matr3;
    int n_z_el1, n_z_el2, n_z_el3;
    int n_z_rows1, n_z_rows2, n_z_rows3;

    int *A1, *A2, *A3;
    int *IA1, *IA2, *IA3;
    struct JA *JA1 = NULL, *JA2 = NULL, *JA3 = NULL, *tmp;

    puts("----------------------------------------------------------------------------------------------------");
    printf("|%4d*%4d |%8d |", n,m, fill);

    // Simple addition
    allocate_matrices(&matr1, &matr2, &matr3, n*m);
    generate_matrix(matr1, n, m, fill);
    generate_matrix(matr2, n, m, fill);

    time_b = tick();
    for (int i = 0; i < ITER; i++)
        add_matrices_simple(matr1, matr2, matr3, n, m);
    time_e = tick();
    time1 = (time_e - time_b) / ITER;

    printf("%15d |%12dB||", (time_e - time_b) / ITER, sizeof(int)*n*m*3);

    // Advanced addition
    count_non_zero(matr1, n, m, &n_z_rows1, &n_z_el1);
    allocate_two_arrays(&A1, &IA1, n_z_el1);

    if (n_z_rows1)
    {
        JA1 = malloc(sizeof(struct JA));
        tmp = JA1;
        for (int i = 0; i < n_z_rows1 - 1; i++) {
            tmp->next = malloc(sizeof(struct JA));
            tmp = tmp->next;
        }
        tmp->next = NULL;
    }

    convert_matrix(matr1, n, m, A1, IA1, JA1);

    count_non_zero(matr2, n, m, &n_z_rows2, &n_z_el2);
    allocate_two_arrays(&A2, &IA2, n_z_el2);

    if (n_z_rows2)
    {
        JA2 = malloc(sizeof(struct JA));
        tmp = JA2;
        for (int i = 0; i < n_z_rows2 - 1; i++) {
            tmp->next = malloc(sizeof(struct JA));
            tmp = tmp->next;
        }
        tmp->next = NULL;
    }


    convert_matrix(matr2, n, m, A2, IA2, JA2);

    allocate_two_arrays(&A3, &IA3, n_z_el1 + n_z_el2);

    JA3 = malloc(sizeof(struct JA));
    JA3->Nk = -1;
    JA3->j = -1;
    JA3->next = NULL;

    time_b = tick();
    for (int i = 0; i < ITER_2; i++)
        add_matrices_advanced(A1, IA1, JA1, n_z_el1, A2, IA2, JA2, n_z_el2, A3, IA3, JA3, &n_z_el3);
    time_e = tick();

    count_non_zero(matr3, n, m, &n_z_rows3, &n_z_el3);

    int size1 = sizeof(int)*n_z_el1*2 + sizeof(struct JA)*n_z_rows1;
    int size2 = sizeof(int)*n_z_el2*2 + sizeof(struct JA)*n_z_rows2;
    int size3 = sizeof(int)*n_z_el3*2 + sizeof(struct JA)*n_z_rows3;
    time2 = time_e - time_b;
    float per = (float)(time2) / (float)(time1);
    printf("%15d |%12dB|%13.2f |\n", (time_e - time_b), size1 + size2 + size3, per);
}
