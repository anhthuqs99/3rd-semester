#include "app.h"
#include "io.h"

void user_input(FILE *f, struct contact_t *user)
{
    //char buf[256];
    fscanf(f, "%s", user->family);
    fscanf(f, "%s", user->name);
    fscanf(f, "%s", user->number);
    fscanf(f, "%s", user->address);
    fscanf(f, "%d", &user->type);
    if (user->type == 0)
    {
        fscanf(f, "%d%d%d", &user->birthday.day, &user->birthday.month, &user->birthday.year);
    }
    else
    {
        fscanf(f, "%s", user->office.work);
        fscanf(f, "%s", user->office.organization);
    }
}
void print_index(int index)
{
    printf("|%-6d|", index);
}
void print_str(const char *str)
{
    printf("%-20s|", str);
}
void print_day(struct birthday_t birthday)
{
    printf("%02d/%02d/%04d          |                    |", birthday.day, birthday.month, birthday.year);
}
void title_print(void)
{
    printf("|%-6s|", "No");
    print_str("FAMILY");
    print_str("NAME");
    print_str("NUMBER");
    print_str("ADDRESS");
    print_str("STATUS (birthday or office)              ");
    printf("\n");
}
void line_print(int LINE)
{
    for (int i = 0; i < LINE; i++)
        printf("%s", "-");
    printf("\n");
}
void user_print(struct contact_t *user)
{
    print_str(user->family);
    print_str(user->name);
    print_str(user->number);
    print_str(user->address);
    if (user->type == 0)
        print_day(user->birthday);
    else
    {
        print_str(user->office.work);
        print_str(user->office.organization);
    }
    printf("\n");
}
void list_user_input(FILE *f, struct list_t *list, int *n)
{
    struct contact_t tmp;
    for (int i = 0; i < MAX_N; i++)
    {
        user_input(f, &tmp);
        list[i].data = tmp;
        list[i].index = i;
    }
    *n = MAX_N;
}
void list_user_print(struct list_t *list, int n)
{
    line_print(133);
    title_print();
    line_print(133);
    for (int i = 0; i < n; i++)
    {
        print_index(i + 1);
        user_print(&(list[i].data));
    }
    line_print(133);
}
void list_key_print(struct list_t *list, int n)
{
    line_print(37);
    printf("|%-6s||%-6s|%-20s|\n", "No", "Source", "NAME");
    line_print(37);
    for (int i = 0; i < n; i++)
    {
        print_index(i + 1);
        print_index(list[i].index + 1);
        print_str(list[i].data.name);
        printf("\n");
    }
    line_print(37);
}
void print_menu(void)
{
    printf("Choose one operation :\n\t"
           "1 : Read from file\n\t"
           "2 : Print infomation of user\n\t"
           "3 : Add information of new user\n\t"
           "4 : Delete user in list by key\n\t"
           "5 : Sort table by key\n\t"
           "6 : Search by birth day\n\t"
           "7 : Print Table index\n\t"
           "0 : Exit\n");
}
int input_choose(int *choose)
{
    print_menu();
    printf("Input your choose: ");
    if (scanf("%d", choose) != 1)
    {
        printf("Input Error\n");
        return ERR_IO;
    }
    return OK;
}
