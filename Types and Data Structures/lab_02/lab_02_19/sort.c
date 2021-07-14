#include "sort.h"

int compare_family(struct contact_t l, struct contact_t r)
{
    return strcmp(l.family, r.family);
}
int compare_name(struct contact_t l, struct contact_t r)
{
    return strcmp(l.name, r.name);
}
int compare_number(struct contact_t l, struct contact_t r)
{
    return strcmp(l.number, r.number);
}
int compare_address(struct contact_t l, struct contact_t r)
{
    return strcmp(l.address, r.address);
}

int bubble_sort_key(struct list_t *b, int n, int (*cmp)(struct contact_t l, struct contact_t r))
{
    clock_t time = clock();
    struct list_t tmp;
    for (int i = 1; i < n; i ++)
        for (int j = 0; j < n - i; j ++)
            if (cmp(b[j].data, b[j + 1].data) > 0)
            {
                tmp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp;
            }
    time = clock() - time;

    return time;
}
int time_bubble_sort_not_key(struct list_t *b, int n)
{
    clock_t time = clock();
    struct list_t tmp;
    int len = n * 100;
    struct list_t a[len];
    for (int i = 0; i < len; i++)
        a[i] = b[i % n];
    for (int i = 1; i < len; i ++)
        for (int j = 0; j < len - i; j ++)
            if (strcmp(a[j].data.family, a[j + 1].data.family) > 0)
            {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
    time = clock() - time;

    return time;
}
int insertion_sort_key(struct list_t *b, int n, int (*cmp)(struct contact_t l, struct contact_t r))
{
    clock_t time = clock();
    struct list_t tmp;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        tmp = b[i];
        while (j >= 0 && (cmp(tmp.data, b[j].data) < 0))
        {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = tmp;
    }
    time = clock() - time;

    return time;
}
int time_insertion_sort_not_key(struct list_t *b, int n)
{
    clock_t time = clock();
    int len = n * 100;
    struct list_t a[len];
    for (int i = 0; i < len; i++)
        a[i] = b[i % n];
    struct list_t tmp;
    for (int i = 1; i < len; i++)
    {
        int j = i - 1;
        tmp = a[i];
        while (j >= 0 && (strcmp(tmp.data.family, a[j].data.family) < 0))
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
    time = clock() - time;

    return time;
}
int time_bubble_sort_key(struct list_t *b, int n, int key)
{
    int time = -1;
    int len = n * 100;
    struct list_t tmp[len];
    for (int i = 0; i < len; i++)
        tmp[i] = b[i % n];
    if (key == 1)
        time = bubble_sort_key(tmp, len, compare_family);
    else if (key == 2)
        time = bubble_sort_key(tmp, len, compare_name);
    else if (key == 3)
        time = bubble_sort_key(tmp, len, compare_number);
    else if (key == 4)
        time = bubble_sort_key(tmp, len, compare_address);

    return time;
}
int time_insertion_sort_key(struct list_t *b, int n, int key)
{
    int time = -1;
    int len = n * 100;
    struct list_t tmp[len];
    for (int i = 0; i < len; i++)
        tmp[i] = b[i % n];
    if (key == 1)
        time = insertion_sort_key(tmp, len, compare_family);
    else if (key == 2)
        time = insertion_sort_key(tmp, len, compare_name);
    else if (key == 3)
        time = insertion_sort_key(tmp, len, compare_number);
    else if (key == 4)
        time = insertion_sort_key(tmp, len, compare_address);

    return time;
}
