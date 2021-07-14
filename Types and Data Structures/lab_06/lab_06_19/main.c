#include "app.h"
#include "tree.h"
#include "time_testing.h"

void print_menu(void)
{
    printf("Menu:\n"
           "\t0: Exit\n"
           "\t1: Print tree\n"
           "\t2: Print balance tree\n"
           "\t3: Find node in tree\n"
           "\t4: Hash table\n"
           "\t5: Show time\n"
           "Input your choose: ");
}

int main(void)
{
    FILE *f;
    struct node_t *root;
    struct node_t *tree;
    struct data_t *a[SIZE];
    int exist;
    int num;
    int done = 0, choose;
    f = fopen("in.txt", "r");
    read_file(f, &root, &tree);
    fclose(f);

    //printf("Source Tree:\n");
    //print2D(tree, 0);

    while (!done)
    {
        choose = 0;
        fflush(stdin);
        print_menu();
        if (scanf("%d", &choose) != 1)
            printf("Invailid input\n");
        switch (choose)
        {
        case 1:
            printf("Tree:\n");
            print2D(tree, 0);
            break;
        case 2:
            printf("Balance tree:\n");
            print2D(root, 0);
            break;
        case 3:
            printf("Input node: ");
            if (scanf("%d", &num) != 1)
            {
                printf("Invailid input\n");
                break;
            }
            exist = find_node(root, num);
            if (exist)
                printf("%d Existing in tree\n", num);
            else
                printf("%d Not existing in tree\n", num);
            break;
            /*
        case 4:
            printf("Input node: ");
            if (scanf("%d", &num) != 1)
            {
                printf("Invailid input\n");
                break;
            }
            int deleted = 0;
            delete_balance(root, num, &deleted);
            if (deleted)
                printf("Deleted\n");
            else
                printf("Node not in tree\n");
            break;
            */
        case 4:
            f = fopen("in.txt", "r");
            creat_array(f, a);
            printf("Hash table:\n");
            print_table(a);
            fclose(f);
            break;
        case 5:
            printf("Input number of node in tree: ");
            if (scanf("%d", &num) != 1)
            {
                printf("Invailid input\n");
                break;
            }
            time_test(num);
            break;
        case 0:
            done = 1;
            break;
        default:
            printf("Invailid input\n");
            break;

        }
    }

    return 0;
}
