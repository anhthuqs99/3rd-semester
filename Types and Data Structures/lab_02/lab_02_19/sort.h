#ifndef SORT_H
#define SORT_H

#include "app.h"
int compare_family(struct contact_t l, struct contact_t r);
int compare_name(struct contact_t l, struct contact_t r);
int compare_number(struct contact_t l, struct contact_t r);
int compare_address(struct contact_t l, struct contact_t r);

int bubble_sort_key(struct list_t *b, int n, int (*cmp)(struct contact_t l, struct contact_t r));
int insertion_sort_key(struct list_t *b, int n, int (*cmp)(struct contact_t l, struct contact_t r));

int time_bubble_sort_not_key(struct list_t *b, int n);
int time_insertion_sort_not_key(struct list_t *b, int n);

int time_bubble_sort_key(struct list_t *b, int n, int key);
int time_insertion_sort_key(struct list_t *b, int n, int key);

#endif // SORT_H
