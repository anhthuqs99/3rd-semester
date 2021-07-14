#include "tree.h"

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int height(struct node_t *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}
struct node_t *new_node(int key)
{
    struct node_t *node = (struct node_t *)malloc(sizeof(struct node_t));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}
struct node_t *right_rotate(struct node_t *y)
{
    struct node_t *x = y->left;
    struct node_t *T2 = x->right;

    //rotation
    x->right = y;
    y->left = T2;

    //Update height
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}
struct node_t *left_rotate(struct node_t *x)
{
    struct node_t *y = x->right;
    struct node_t *T2 = y->left;

    //rotation
    y->left = x;
    x->right = T2;

    //Update height
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int get_balance(struct node_t *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct node_t *insert_balance(struct node_t *node, int key)
{
    if (node == NULL)
        return new_node(key);
    if (key < node->key)
        node->left = insert_balance(node->left, key);
    else if (key > node->key)
        node->right = insert_balance(node->right, key);
    else
        return node;

    //update height
    node->height = 1 +max(height(node->left), height(node->right));

    //get balance
    int balance = get_balance(node);

    //rebalance

    //left left rotate
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);
    //right right rotate
    if (balance < -1 && key > node->right->key)
        return left_rotate(node);
    //left right rotate
    if (balance > 1 && key > node->left->key)
    {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    //right left rotate
    if (balance < -1 && key < node->right->key)
    {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

//loop down to find the leftmost leaf
struct node_t *min_value_node(struct node_t *node)
{
    struct node_t *curr = node;
    while(curr && curr->left)
        curr = curr->left;

    return curr;
}

struct node_t *delete_balance(struct node_t *root, int key, int *deleted)
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete_balance(root->left, key, deleted);
    else if (key > root->key)
        root->right = delete_balance(root->right, key, deleted);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct node_t *tmp = root->left ? root->left : root->right;

            if (tmp == NULL)
            {
                tmp = root;
                root= NULL;
            }
            else
                *root = *tmp;
            //free
            free(tmp);
        }
        else
        {
            struct node_t *tmp = min_value_node(root->right);
            root->key = tmp->key;

            root->right = delete_balance(root->right, tmp->key, deleted);
        }
        *deleted = 1;

    }
    // if the tree had only one node then return NULL
    if (root == NULL)
        return root;
    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = get_balance(root);

    //rebalance tree

    //left left rotate
    if (balance > 1 && key < root->left->key)
        return right_rotate(root);
    //right right rotate
    if (balance < -1 && key > root->right->key)
        return left_rotate(root);
    //left right rotate
    if (balance > 1 && key > root->left->key)
    {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    //right left rotate
    if (balance < -1 && key < root->right->key)
    {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void print2D(struct node_t *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2D(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("|--------%d\n", root->key);

    print2D(root->left, space);
}
struct node_t *insert_normal(struct node_t *node, int key)
{
    if (node == NULL)
        return (new_node(key));
    if (key < node->key)
        node->left = insert_normal(node->left, key);
    else if (key > node->key)
        node->right = insert_normal(node->right, key);
    node->height = 1 +max(height(node->left), height(node->right));
    return node;
}
void read_file(FILE *f, struct node_t **root, struct node_t **tree)
{
    struct node_t *tmp1 = NULL;
    struct node_t *tmp2 = NULL;
    int value;
    //struct node_t *root = NULL;
    while(fscanf(f, "%d", &value) == 1)
    {
        if (!tmp1)
            tmp1 = insert_normal(tmp1, value);
        else insert_normal(tmp1, value);
        tmp2 = insert_balance(tmp2, value);
    }
    *tree = tmp1;
    *root = tmp2;
}
int find_node(struct node_t *node, int key)
{
    if (node == NULL)
        return 0;
    if (node->key == key)
        return 1;
    if (find_node(node->left, key))
        return 1;
    return (find_node(node->right, key));
}
