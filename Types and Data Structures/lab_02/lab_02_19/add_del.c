#include "add_del.h"

int user_input_screen(struct contact_t *tmp)
{
    printf("Input Family (len < 20): ");
    if (scanf("%s", tmp->family) != 1)
        return ERR_IO;
    printf("Input Name (len < 20): ");
    if (scanf("%s", tmp->name) != 1)
        return ERR_IO;
    printf("Input Phone number (len < 20): ");
    if (scanf("%s", tmp->number) != 1)
        return ERR_IO;
    printf("Input address (len < 20): ");
    if (scanf("%s", tmp->address) != 1)
        return ERR_IO;
    printf("Type of status (0: birthday, 1: office): ");
    if (scanf("%d", &tmp->type) != 1)
        return ERR_IO;
    if (tmp->type == 0)
    {
        printf("Input date of birth (format: DD MM YYYY): ");
        if (scanf("%d%d%d", &tmp->birthday.day, &tmp->birthday.month, &tmp->birthday.year) != 3)
            return ERR_IO;
        if (tmp->birthday.day <= 0 || tmp->birthday.day > 31)
            return ERR_RANGE;
        if (tmp->birthday.month <= 0 || tmp->birthday.month > 12)
            return ERR_RANGE;
        if (tmp->birthday.year <= 0)
            return ERR_RANGE;
    }
    else if (tmp->type == 1)
    {
        printf("Input work (len < 20): ");
        if (scanf("%s", tmp->office.work) != 1)
            return ERR_IO;
        printf("Input organization: ");
        if (scanf("%s", tmp->office.organization) != 1)
            return ERR_IO;
    }
    else
        return ERR_IO;
    return OK;
}
int user_addition(struct list_t *b, int *n, int index)
{
    struct contact_t tmp;
    int rc = user_input_screen(&tmp);
    if (rc == OK)
    {
        for (int i = *n; i > index; i--)
        {
            b[i] = b[i - 1];
        }
        b[index].data = tmp;
        b[index].index = index;
        (*n)++;
    }
    return rc;
}
int delete(struct contact_t user, struct contact_t cmp, int key)
{
    if (key == 1)
        return (strcmp(user.family, cmp.family) == 0);
    else if (key == 2)
        return (strcmp(user.name, cmp.name) == 0);
    else if (key == 3)
        return (strcmp(user.number, cmp.number) == 0);
    else if (key == 4)
        return (strcmp(user.address, cmp.address) == 0);
    else if (key == 5 && user.type == 0)
        return ((user.birthday.day == cmp.birthday.day) && (user.birthday.month == cmp.birthday.month)
                && (user.birthday.year == cmp.birthday.year));
    else if (key == 6 && user.type == 1)
        return (strcmp(user.office.work, cmp.office.work) == 0);
    else if (key == 7 && user.type == 1)
        return (strcmp(user.office.organization, cmp.office.organization) == 0);
    return 0;
}
void user_deletion_by_index(struct list_t *b, int *n, int index)
{
    for (int j = index; j < *n - 1; j++)
        b[j] = b[j + 1];
    (*n)--;
}
void user_deletion(struct list_t *b, int *n,struct contact_t cmp, int key,
                   int (*delete)(struct contact_t user, struct contact_t cmp, int key))
{
    int i = 0;
    while (i < *n)
    {
        if (delete(b[i].data, cmp, key))
            user_deletion_by_index(b, n, i);
        else i++;
    }
}
