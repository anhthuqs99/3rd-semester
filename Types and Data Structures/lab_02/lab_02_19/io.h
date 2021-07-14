#ifndef _IO_H_
#define _IO_H_

void user_input(FILE *f, struct contact_t *user);
void print_index(int index);
void line_print(int LINE);
void title_print();
void print_str(const char *str);
void print_day(struct birthday_t birthday);
void user_print(struct contact_t *user);
void list_user_input(FILE *f, struct list_t *list, int *n);
void list_user_print(struct list_t *list, int n);
void list_key_print(struct list_t *list, int n);
void print_menu(void);
int input_choose(int *choose);

#endif // _IO_H_
