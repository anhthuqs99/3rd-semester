#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
#include <time.h>

#include "input.h"
#include "alloc.h"
#include "matrices.h"
#include "output.h"
#include "time_testing.h"

int main()
{
	setbuf(stdout, NULL);
    srand(time(0));

    int option;
    int flag = 0;
    int fill = 20; // percentage of non-zero elements in matrix

    int *matr1, *matr2, *matr3;
    int n, m;
    int n_z_el1, n_z_el2, n_z_el3;
    int n_z_rows1, n_z_rows2;

    int *A1, *A2, *A3;
    int *IA1, *IA2, *IA3;
    struct JA *JA1 = NULL, *JA2 = NULL, *JA3 = NULL, *tmp;


    printf("This program will calculate sum of int matrices.\n");

    printf("If you want to ONLY time tes input n \n");
    option = input_flag("Sum two matrices ");
    if (option)
    {
        option = input_flag("Input matrix by hand ");
        input_size("Input size of matrices (n m): ", &n, &m);

        flag = allocate_matrices(&matr1, &matr2, &matr3, n * m);
        if (flag) {
            printf("\nAllocation error.");
            return flag;
        }

        // Creation of two matrices
        if (option) {
            printf("\nIn input option. To finish input enter any non-digit char.\n");
            printf("\nInput first matrix:\n");
            input_matrix(matr1, n, m);
            printf("\nInput second matrix:\n");
            input_matrix(matr2, n, m);
        } else {
            generate_matrix(matr1, n, m, fill);
            generate_matrix(matr2, n, m, fill);
        }

        // First
        count_non_zero(matr1, n, m, &n_z_rows1, &n_z_el1);
        allocate_two_arrays(&A1, &IA1, n_z_el1);

        if (n_z_rows1) {
            JA1 = malloc(sizeof(struct JA));
            tmp = JA1;
            for (int i = 0; i < n_z_rows1 - 1; i++) {
                tmp->next = malloc(sizeof(struct JA));
                tmp = tmp->next;
            }
            tmp->next = NULL;
        }
        convert_matrix(matr1, n, m, A1, IA1, JA1);

        // Second
        count_non_zero(matr2, n, m, &n_z_rows2, &n_z_el2);
        allocate_two_arrays(&A2, &IA2, n_z_el2);

        if (n_z_rows2) {
            JA2 = malloc(sizeof(struct JA));
            tmp = JA2;
            for (int i = 0; i < n_z_rows2 - 1; i++) {
                tmp->next = malloc(sizeof(struct JA));
                tmp = tmp->next;
            }
            tmp->next = NULL;
        }

        convert_matrix(matr2, n, m, A2, IA2, JA2);


        // Addition
        allocate_two_arrays(&A3, &IA3, n_z_el1 + n_z_el2);
        //add_matrices_simple(matr1, matr2, matr3, n, m);
        JA3 = malloc(sizeof(struct JA));
        JA3->Nk = -1;
        JA3->j = -1;
        JA3->next = NULL;

        add_matrices_simple(matr1, matr2, matr3, n, m);
        add_matrices_advanced(A1, IA1, JA1, n_z_el1, A2, IA2, JA2, n_z_el2, A3, IA3, JA3, &n_z_el3);

        option = input_flag("\nOutput matrices ");
        if (option) {
            puts("\nFirst Matrix:");
            print_matrix(matr1, n, m);
            print_advanced(A1, IA1, JA1, n_z_el1);

            puts("\nSecond Matrix:");
            print_matrix(matr2, n, m);
            print_advanced(A2, IA2, JA2, n_z_el2);

            puts("\nResult:");
            print_matrix(matr3, n, m);
            print_advanced(A3, IA3, JA3, n_z_el3);
        }

        // Free memory
        free_all(matr1, A1, IA1, JA1);
        free_all(matr2, A2, IA2, JA2);
        free_all(matr3, A3, IA3, JA3);
    }

    // Time testing
    fflush(stdin);
    option = input_flag("\nTime testing ");

    if (option)
    {
        puts("Time testing: ");
        puts("----------------------------------------------------------------------------------------------------");
        puts("| Range    |elements |Normal :                      ||declare   :                   |time          |");
        puts("|          |         |time               size       ||   time           size        |declare/normal|");
        time_testing(200, 200, 1);
        time_testing(200, 200, 2);
        time_testing(200, 200, 6);
        time_testing(500, 500, 1);
        time_testing(500, 500, 2);
        time_testing(500, 500, 8);
        puts("----------------------------------------------------------------------------------------------------");
    }
    return 0;
}
