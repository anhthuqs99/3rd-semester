#ifndef LIST_H
#define LIST_H

#include "app.h"
#include "list.h"

struct list_t
{
    char *value;
    struct list_t *next;
};

int is_full(struct list_t *head);
struct list_t *push_list(struct list_t *head, char *value);
struct list_t *pop_list(struct list_t *head);
void print_list(struct list_t *head);
void free_list(struct list_t *head);

#endif // LIST_H
