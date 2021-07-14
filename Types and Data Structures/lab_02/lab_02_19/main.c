#include "app.h"
#include "io.h"
#include "add_del.h"
#include "find.h"
#include "sort.h"

void print_code_error(int rc)
{
    if (rc == OK)
        printf("Succed!\n");
    if (rc == ERR_IO)
        printf("Error Input!\n");
    if (rc == ERR_FILE)
        printf("Can't open file!\n");
    if (rc == ERR_RANGE)
        printf("Number out of range!\n");
}

int choose_1(struct list_t *b, int *n)
{
    FILE *f;
    char str[256];
    printf("Input file name: ");
    if (scanf("%s", str) != 1)
        return ERR_IO;
    f = fopen(str, "r");
    if (!f)
        return ERR_FILE;
    list_user_input(f, b, n);
    fclose(f);
    return OK;
}
void choose_2(struct list_t *b, int n)
{
    list_user_print(b, n);
}
void choose_3(struct list_t *b, int *n)
{
    int index;
    int rc = OK;
    printf("Input index of user will be insert (0 < index <= %d): ", *n + 1);
    if (scanf("%d", &index) != 1)
        rc = ERR_IO;
    if (index <= 0 || index > *n + 1)
        rc = ERR_RANGE;
    if (rc == OK)
        rc = user_addition(b, n, index - 1);
    printf("Addition: ");
    print_code_error(rc);
}
void print_key_delete(void)
{
    printf("\n\t");
    printf("1 : Family\n\t"
           "2 : Name\n\t"
           "3 : Phone number\n\t"
           "4 : Address\n\t"
           "5 : Birthday\n\t"
           "6 : Work\n\t"
           "7 : Organization\n");
    printf("Choose one key of deletion: ");
}
int input_cmp(struct contact_t *cmp, int key)
{
    if (key == 1)
    {
        printf("Input family (len < 20): ");
        if (scanf("%s", cmp->family) != 1)
            return ERR_IO;
    }
    else if (key == 2)
    {
        printf("Input name (len < 20) :");
        if (scanf("%s", cmp->name) != 1)
            return ERR_IO;
    }
    else if (key == 3)
    {
        printf("Input phone number (len < 20) :");
        if (scanf("%s", cmp->number) != 1)
            return ERR_IO;
    }
    else if (key == 4)
    {
        printf("Input address (len < 20) :");
        if (scanf("%s", cmp->address) != 1)
            return ERR_IO;
    }
    else if (key == 5)
    {
        printf("Input birthday (format DD MM YYYY): ");
        if (scanf("%d%d%d", &cmp->birthday.day, &cmp->birthday.month, &cmp->birthday.year) != 3)
            return ERR_IO;
    }
    else if (key == 6)
    {
        printf("Input work (len < 20) :");
        if (scanf("%s", cmp->office.work) != 1)
            return ERR_IO;
    }
    else if (key == 7)
    {
        printf("Input organization (len < 20) :");
        if (scanf("%s", cmp->office.organization) != 1)
            return ERR_IO;
    }
    return OK;
}

void choose_4(struct list_t *b, int *n)
{
    int rc = OK;
    int key;
    struct contact_t cmp;
    print_key_delete();
    if (scanf("%d", &key) != 1)
        rc = ERR_IO;
    if (rc == OK && (key <= 0 || key > 7))
        rc = ERR_RANGE;
    if (rc == OK)
    {
        rc = input_cmp(&cmp, key);
    }
    if (rc == OK)
        user_deletion(b, n, cmp, key, delete);
    printf("Deletion: ");
    print_code_error(rc);
}
void print_key_sort(void)
{
    printf("\n\t");
    printf("1 : Family\n\t"
           "2 : Name\n\t"
           "3 : Phone number\n\t"
           "4 : Address\n\t");
    printf("Choose one key of sort: ");
}
void choose_5(struct list_t *b, int n)
{
    int rc = OK;
    int key;
    int time_bubble_sort, time_insertion_sort, time_bubble_sort_not_using_key, time_insertion_sort_not_using_key;
    print_key_sort();
    if (scanf("%d", &key) != 1)
        rc = ERR_IO;
    if (rc == OK)
    {
        time_bubble_sort = time_bubble_sort_key(b, n, key);
        time_insertion_sort = time_insertion_sort_key(b, n, key);
        time_bubble_sort_not_using_key = time_bubble_sort_not_key(b, n);
        time_insertion_sort_not_using_key = time_insertion_sort_not_key(b, n);
        //printf("time bubble sort: %d %d\n", time_bubble_sort, time_bubble_sort_not_using_key);
        //printf("time insertion sort: %d %d\n", time_insertion_sort, time_insertion_sort_not_using_key);
        printf("Bubble sort: %d%s\n", (int)((float)(time_bubble_sort_not_using_key * 100 / time_bubble_sort)), "%");
        printf("Bubble sort: %d%s\n", (int)((float)(time_insertion_sort_not_using_key * 100 / time_insertion_sort)), "%");
        if (key == 1)
            bubble_sort_key(b, n, compare_family);
        else if (key == 2)
            bubble_sort_key(b, n, compare_name);
        else if (key == 3)
            bubble_sort_key(b, n, compare_number);
        else if (key == 4)
            bubble_sort_key(b, n, compare_address);
		//int size = sizeof(b[0]) * n;
		//printf("%d\n", size);
    }
    print_code_error(rc);
}
void choose_6(struct list_t *b, int n)
{
    int rc = OK;
    int day, month;
    printf("Input birthday (format: DD MM): ");
    if (scanf("%d%d", &day, &month) != 2)
        rc = ERR_IO;
    if (rc == OK)
        find_birthday(b, n, day, month);
    printf("Find user have birthday in week: ");
    print_code_error(rc);
}
void choose_7(struct list_t *b, int n)
{
    list_key_print(b, n);
}
int main(void)
{
    int rc = OK;
    int STOP = 0;
    int n;
   struct list_t b[MAX_N * 2];
    FILE *f;
    f = fopen("test.txt", "r");
    list_user_input(f, b, &n);
    list_user_print(b, n);
    fclose(f);
    LOOP: do
    {
        int choose = 0;
        rc = input_choose(&choose);
        if (rc != OK)
        {
            print_code_error(rc);
            goto LOOP;
        }
        switch (choose)
        {
        case 1:
        {
            rc = choose_1(b, &n);
            print_code_error(rc);
        }
            break;
        case 2:
            choose_2(b, n);
            break;
        case 3:
            choose_3(b, &n);
            break;
        case 4:
            choose_4(b, &n);
            break;
        case 5:
            choose_5(b, n);
            break;
        case 6:
            choose_6(b, n);
            break;
        case 7:
            choose_7(b, n);
            break;
        case 0:
            STOP = 1;
            break;
        default:
            printf("Input Error\n");
        }

    }
    while (!STOP);

    return rc;
}
