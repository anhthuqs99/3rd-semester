#ifndef TREE_H
#define TREE_H

#include "app.h"

int max(int a, int b);
int height(struct node_t *node);
struct node_t *new_node(int key);

struct node_t *right_rotate(struct node_t *y);
struct node_t *left_rotate(struct node_t *x);

int get_balance(struct node_t *node);
struct node_t *insert_balance(struct node_t *node, int key);
struct node_t *min_value_node(struct node_t *node);
struct node_t *delete_balance(struct node_t *root, int key, int *deleted);
void print2D(struct node_t *root, int space);

void read_file(FILE *f, struct node_t **root, struct node_t **tree);

struct node_t *insert_normal(struct node_t *node, int key);

int find_node(struct node_t *node, int key);

#endif // TREE_H
