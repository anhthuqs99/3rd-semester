#include "hash.h"

struct data_t *creat_data(int value)
{
    struct data_t *tmp = malloc(sizeof(struct data_t));
    if (tmp)
    {
        tmp->value = value;
        tmp->next = NULL;
    }
    return tmp;
}
struct data_t *add_begin(struct data_t *head, struct data_t *node)
{
    node->next = head;
    return node;
}
int get_key(int num)
{
    return num % SIZE;
}

void creat_array(FILE *f, struct data_t* a[SIZE])
{
    //FILE *f;
    int num, key;
    struct data_t *node;
    //f = fopen(FILE_NAME, "r");
    for (int i = 0; i < SIZE; i++)
        a[i] = NULL;
    while (fscanf(f, "%d", &num) == 1)
    {
        node = creat_data(num);
        key = get_key(num);
        a[key] = add_begin(a[key], node);
    }
}
void print_table(struct data_t* a[SIZE])
{
    struct data_t *head;
    for (int key; key < SIZE; key++)
    {
        head = a[key];
        if (head)
            printf("%d : ", key);
        while (head)
        {
            printf("%d -> ", head->value);
            head = head->next;
        }
        if (a[key])
            printf("NULL\n");
    }
    printf("\n");
}
int find_in_table(struct data_t* a[SIZE], int value)
{
    int key = get_key(value);
    struct data_t *head = a[key];
    while (head)
    {
        if (head->value == value)
            return 1;
        head = head->next;
    }
    return 0;
}

