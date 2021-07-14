#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "output.h"
#include "matrices.h"


void generate_matrix(int *matr, int n, int m, int fill)
{
    int chance;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            chance = rand() % 100;
            if (chance > fill)
                matr[i*m+j] = 0;
            else
                matr[i*m+j] = rand() % 10;
        }
}


void input_matrix(int *matr, int n, int m)
{
    int i = 0, j = 0, value = 0, OK = 0, STOP = 0;
    printf("(Input 0 0 0 to stop)\n");
    fflush(stdin);
    while (!STOP)
    {
        OK = 0;
        while (!OK)
        {
            OK = 1;
            printf("Input (i j value): ");
            if (scanf("%d %d %d", &i, &j, &value) != 3)
            {
                OK = 0;
                printf("Input ERR. Try again:\n");
            }
            else
            {
                if (i == 0 && j == 0 && value == 0)
                    STOP = 1;
                else if (i >= 0 && j >= 0 && i < n && j < m)
                    matr[i*m+j] = value;
                else
                {
                    printf("ERR: wrong index (i: [0; %d], j: [0, %d])\n", n - 1, m - 1);
                    OK = 0;
                }
            }
            fflush(stdin);
        }
    }
}


void count_non_zero(const int *matr, int n, int m, int *non_zero_col, int *non_zero_elements)
{
    *non_zero_col = 0;
    *non_zero_elements = 0;

    int col_counted = 0;

	for (int j = 0; j < m; j++)
    {
        col_counted = 0;
		for (int i = 0; i < n; i++)
            if (matr[i*m+j] != 0)
            {
                (*non_zero_elements)++;
                if (!col_counted)
                {
                    col_counted = 1;
                    (*non_zero_col)++;
                }
            }
    }
}


void convert_matrix(const int *matr, int n, int m, int *A, int *IA, struct JA *JA)
{
    int A_curr = 0;
    int An_curr = 0;
    int first_in_col = 1;

	for (int j = 0; j < m; j++)
    {
        first_in_col = 1;
		for (int i = 0; i < n; i++)
            if (matr[i * m + j] != 0)
            {
                A[A_curr] = matr[ i * m + j];
                IA[A_curr] = i;

                if (first_in_col)
                {
                    first_in_col = 0;
                    JA->Nk = A_curr;
                    JA->j = j;
                    JA = JA->next;
                }
                A_curr++;
            }
    }
}


void add_matrices_simple(const int *matr1, const int *matr2, int *matr3, int n, int m)
{
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
            matr3[i*m+j] = matr1[i*m+j] + matr2[i*m+j];
}


void add_matrices_advanced(const int *A1, const int *IA1, struct JA *JA1, int n_z_el1,
                           const int *A2, const int *IA2, struct JA *JA2, int n_z_el2,
                           int *A3, int *IA3, struct JA *JA3, int *n_z_el3)
{
    *n_z_el3 = 0;

    struct JA *tmp1 = JA1, *tmp2 = JA2, *tmp3 = JA3;

    while (tmp1 && tmp2)
    {
        if (tmp1->j < tmp2->j)
        {
            copy_row(A1, IA1, tmp1, n_z_el1, A3, IA3, tmp3, n_z_el3);
            tmp1 = tmp1->next;
        }
        else if (tmp2->j < tmp1->j)
        {
            copy_row(A2, IA2, tmp2, n_z_el2, A3, IA3, tmp3, n_z_el3);
            tmp2 = tmp2->next;
        }
        else
        {
            add_rows(A1, IA1, tmp1, n_z_el1, A2, IA2, tmp2, n_z_el2, A3, IA3, tmp3, n_z_el3);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        if (tmp3->next)
            tmp3 = tmp3->next;
    }

    while (tmp1)
    {
        copy_row(A1, IA1, tmp1, n_z_el1, A3, IA3, tmp3, n_z_el3);
        tmp1 = tmp1->next;

        if (tmp3->next)
            tmp3 = tmp3->next;
    }

    while (tmp2)
    {
        copy_row(A2, IA2, tmp2, n_z_el2, A3, IA3, tmp3, n_z_el3);
        tmp2 = tmp2->next;

        if (tmp3->next)
            tmp3 = tmp3->next;
    }
}


// Copy row from 1st matrix to second
void copy_row(const int *A1, const int *IA1, struct JA *JA1, int max_iel,
              int *A3, int *IA3, struct JA *JA3, int *n_z_el3)
{
    // Determine indexes of elements to copy
    int i_from = JA1->Nk;
    int i_to;

    if (JA1->next)
    {
        i_to = (JA1->next)->Nk;
    }
    else
    {
        i_to = max_iel;
    }

    // Allocate new row
    if (JA3->j != -1)
    {
        JA3->next = malloc(sizeof(struct JA));
        JA3 = JA3->next;
        JA3->next = NULL;
    }

    // Fill
    JA3->j = JA1->j;
    JA3->Nk = *n_z_el3;

    for (int i = i_from; i < i_to; i++)
    {
        A3[*n_z_el3] = A1[i];
        IA3[*n_z_el3] = IA1[i];
        (*n_z_el3)++;
    }
}

void add_rows(const int *A1, const int *IA1, struct JA *JA1, int max_i1el,
              const int *A2, const int *IA2, struct JA *JA2, int max_i2el,
              int *A3, int *IA3, struct JA *JA3, int *n_z_el3)
{
    // Allocate new row
    if (JA3->j != -1)
    {
        JA3->next = malloc(sizeof(struct JA));
        JA3 = JA3->next;
        JA3->next = NULL;
    }

    JA3->j = JA1->j;
    JA3->Nk = *n_z_el3;

    // Find indexes
    int i1_from = JA1->Nk;
    int i1_to, i1 = i1_from;

    if (JA1->next)
        i1_to = (JA1->next)->Nk;
    else
        i1_to = max_i1el;

    int i2_from = JA2->Nk;
    int i2_to, i2 = i2_from;

    if (JA2->next)
        i2_to = (JA2->next)->Nk;
    else
        i2_to = max_i2el;

    // Add rows
    while ((i1 < i1_to) && (i2 < i2_to))
    {
        if (IA1[i1] < IA2[i2])
        {
            IA3[*n_z_el3] = IA1[i1];
            A3[*n_z_el3] = A1[i1++];
        }
        else if (IA2[i2] < IA1[i1])
        {
            IA3[*n_z_el3] = IA2[i2];
            A3[*n_z_el3] = A2[i2++];
        }
        else
        {
            IA3[*n_z_el3] = IA1[i1];
            A3[*n_z_el3] = A1[i1++] + A2[i2++];
        }
        (*n_z_el3)++;
    }

    // if some elements left in 1 or 2
    while (i1 < i1_to)
    {
        IA3[*n_z_el3] = IA1[i1];
        A3[*n_z_el3] = A1[i1++];
        (*n_z_el3)++;
    }

    while (i2 < i2_to)
    {
        IA3[*n_z_el3] = IA2[i2];
        A3[*n_z_el3] = A2[i2++];
        (*n_z_el3)++;
    }
}
