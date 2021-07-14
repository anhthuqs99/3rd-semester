#include "find.h"

int birthday_in_week(struct contact_t user, int day, int month)
{
    return (((user.birthday.month == month) && (user.birthday.day - day >= 0) && (user.birthday.day - day <= 7)) ||
            ((user.birthday.month == (month + 1) % 12) && (30 + user.birthday.day - day <= 7)));
}
void find_birthday(struct list_t *b, int n, int day, int month)
{
    int count = 0;
    line_print(133);
    title_print();
    line_print(133);
    for (int i = 0; i < n; i++)
        if (b[i].data.type == 0 && birthday_in_week(b[i].data, day, month))
        {
            count++;
            print_index(i);
            user_print(&(b[i].data));
        }
    if (count == 0)
        printf("|%-132s|\n", "Not found");
    line_print(133);
}
//Нгуен Ань Тхы
