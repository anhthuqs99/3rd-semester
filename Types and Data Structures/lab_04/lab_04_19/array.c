#include "array.h"

int push_array_2(char ***pcur, char **pend, char *value)
{
    if (*pcur >= pend)
    {
        printf("Overflow array Stack\n");
        return ERR_OVER;
    }
    (*pcur)++;
    strcpy(**pcur, value);
    return OK;
}
int pop_array(char **pcur, char *pbeg)
{
    if(*pcur < pbeg)
    {
        printf("Array stack empty\n");
        return ERR_EMPTY;
    }
    (*pcur)--;
    return OK;
}
int pop_array_2(char ***pcur, char **pbeg)
{
    if(*pcur < pbeg)
    {
        printf("Array stack empty\n");
        return ERR_EMPTY;
    }
    (*pcur)--;
    return OK;
}
void print_array(char *pbeg, char *pcur)
{
    if (pbeg > pcur)
        printf("Array stack empty\n");
    else
        printf("Array stack of words in reverse order: ");
    for (;pcur >= pbeg; pcur--)
        printf("%c ", *pcur);
    printf("\n");
}
void print_array_2(char **pbeg, char **pcur)
{
    if (pbeg > pcur)
        printf("Array stack empty\n");
    else
        printf("Array stack of words in reverse order: ");
    for (char **p = pcur; p >= pbeg; p--)
        printf("%s ", *p);
    printf("\n");
}
void free_array(char **array, int size)
{
    for (int i = 0; i < size; i++)
        free(array[i]);
    free(array);
}
