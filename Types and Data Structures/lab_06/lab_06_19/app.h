#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

#define FILE_NAME "data.txt"
#define COUNT 10
#define SIZE 13

struct node_t
{
    int key;
    struct node_t *left;
    struct node_t *right;
    int height;
};

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

struct data_t
{
    int value;
    struct data_t *next;
};

#endif // APP_H
