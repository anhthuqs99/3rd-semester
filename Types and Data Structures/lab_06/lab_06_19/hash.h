#ifndef HASH_H
#define HASH_H

#include "app.h"

void creat_array(FILE *f, struct data_t* a[SIZE]);
int find_in_table(struct data_t* a[SIZE], int value);
void print_table(struct data_t* a[SIZE]);

#endif // HASH_H
