#include "app.h"
#include "array.h"
#include "list.h"
#include "time_using.h"
#include <ctype.h>

void print_operation(void)
{
    printf("Range of stack: 5 elements\n\t"
           "Menu:\n\t"
           "0 : Exit\n\t"
           "1 : Push to array\n\t"
           "2 : Pop from array\n\t"
           "3 : Show array\n\n\t"
           "4 : Push to list\n\t"
           "5 : Pop from list\n\t"
           "6 : Show list\n\t"
           "7 : Show time\n"
           "Choose one operation: ");
}
int get_string(char value[MAX + 1])
{
    fflush(stdin);
    //setbuf(stdin, NULL);
    //printf("                          /**********/\n");
    printf("Input word (contain only letters and length < 256): ");
    if (!gets(value))
        return ERR_IO;
    if (value[strlen(value) - 1] == '\n')
        value[strlen(value) - 1] = 0;
    if (strlen(value) > MAX || strlen(value) <= 0)
        return ERR_IO;
    for (int i = 0; i < strlen(value); i++)
        if (!isalpha(value[i]))
            return ERR_IO;
    return OK;
}
int main(void)
{
	setbuf(stdout, NULL);
    int choose;
    char **array = calloc(MAX_N, sizeof(char *));
    for (int i = 0; i < MAX_N; i++)
        array[i] = calloc(MAX + 1, sizeof(char));
    char **pcur = array - 1;
    struct list_t *head = NULL;
    while (1)
    {
        char value[MAX + 1];
        choose = 0;
        print_operation();
        fflush(stdin);
        if (scanf("%d", &choose) == 1)
        {
            switch (choose)
            {
            case 0:
                free_array(array, MAX_N);
                free_list(head);
                return 0;
            case 1:
                if (get_string(value) == OK)
                {
                    if(push_array_2(&pcur, array + MAX_N - 1, value) == OK)
                        printf("Added\n");
                }
                else
                {
                    //print_array_2(array, pcur);
                    printf("Invalid input\n");
                }
                break;
            case 2:
                if (pop_array_2(&pcur, array) == OK)
                    printf("Deleted\n");
                break;
            case 3:
                print_array_2(array, pcur);
                break;
            case 4:
                if (get_string(value) == OK)
                {
                    if (is_full(head) == 1)
                        printf("Overflow list stack\n");
                    else
                        head = push_list(head, value);
                }
                else
                    printf("Invailid input\n");
                break;
            case 5:
                head = pop_list(head);
                break;
            case 6:
                print_list(head);
                break;
            case 7:
                time_using(10000);
                break;
            default:
                printf("Invailid input\n");
                break;
            }
        }
        else
            printf("Invailid input\n");
    }
    return 0;
}
