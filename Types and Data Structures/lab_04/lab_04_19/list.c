#include "list.h"

struct list_t *push_list(struct list_t *head, char *value)
{
    struct list_t *tmp = malloc(sizeof(struct list_t));
    if (tmp)
    {
        tmp->value = malloc(sizeof(char) * strlen(value));
        strcpy(tmp->value, value);
        tmp->next = head;
    }
    return tmp;
}
int is_full(struct list_t *head)
{
    int count = 0;
    struct list_t *iter = head;
    while (iter)
    {
        count++;
        iter = iter->next;
    }
    if (count >= MAX_N)
        return 1;
    return 0;
}
struct list_t *pop_list(struct list_t *head)
{
    if (!head)
        printf("List stack is empty\n");
    else
    {
        struct list_t *tmp = head->next;
        free(head);
        return tmp;
    }
    return NULL;
}
void print_list(struct list_t *head)
{
    struct list_t *iter = head;
    if (!head)
        printf("List stack is empty");
    else
        printf("List stack of words in reverse order: ");
    while (iter)
    {
        printf("%s ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}
void node_free(struct list_t *node)
{
    free(node->value);
    free(node);
}
void free_list(struct list_t *head)
{
    struct list_t *iter = head;
    while (head)
    {
        head = head->next;
        node_free(iter);
        iter = head;
    }
}
