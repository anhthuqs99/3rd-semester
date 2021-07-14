#ifndef MATRICES_H
#define MATRICES_H

struct JA
{
    int j;
    int Nk;

    struct JA *next;
};

void generate_matrix(int *matr, int n, int m, int fill);
void input_matrix(int *matr, int n, int m);

void count_non_zero(const int *matr, int n, int m, int *non_zero_col, int *non_zero_elements);
void convert_matrix(const int *matr, int n, int m, int *A, int *IA, struct JA *JA);

void add_matrices_simple(const int *matr1, const int *matr2, int *matr3, int n, int m);
void add_matrices_advanced(const int *A1, const int *IA1, struct JA *JA1, int n_z_el1,
                           const int *A2, const int *IA2, struct JA *JA2, int n_z_el2,
                           int *A3, int *IA3, struct JA *JA3, int *n_z_el3);

void copy_row(const int *A1, const int *IA1, struct JA *JA1, int max_iel,
              int *A3, int *IA3, struct JA *JA3, int *n_z_el3);
void add_rows(const int *A1, const int *IA1, struct JA *JA1, int max_i1el,
              const int *A2, const int *IA2, struct JA *JA2, int max_i2el,
              int *A3, int *IA3, struct JA *JA3, int *n_z_el3);

#endif // MATRICES_H
