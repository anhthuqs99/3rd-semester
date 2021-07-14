#ifndef ADD_DEL_H
#define ADD_DEL_H

#include "app.h"
#include "io.h"

int user_input_screen(struct contact_t *tmp);
int user_addition(struct list_t *b, int *n, int index);

int delete(struct contact_t user, struct contact_t cmp, int key);
void user_deletion_by_index(struct list_t *b, int *n, int index);
void user_deletion(struct list_t *b, int *n, struct contact_t cmp, int key,
                   int (*delete)(struct contact_t user, struct contact_t cmp, int key));

#endif // ADD_DEL_H
