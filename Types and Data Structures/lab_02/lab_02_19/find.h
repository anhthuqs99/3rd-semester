#ifndef FIND_H
#define FIND_H

#include "app.h"
#include "io.h"

int birthday_in_week(struct contact_t user, int day, int month);
void find_birthday(struct list_t *b, int n, int day, int month);

#endif // FIND_H
