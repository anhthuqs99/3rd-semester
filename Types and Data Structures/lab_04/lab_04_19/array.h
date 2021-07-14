#ifndef ARRAY_H
#define ARRAY_H

#include "app.h"

int push_array_2(char ***pcur, char **pend, char *value);
int pop_array_2(char ***pcur, char **pbeg);
void print_array_2(char **pbeg, char **pcur);
void free_array(char **array, int size);

#endif // ARRAY_H
