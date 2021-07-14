#ifndef _APP_H_
#define _APP_H_

#include <stdio.h>
#include <string.h>
#include <time.h>

#define OK 0
#define ERR_IO 1
#define ERR_FILE 2
#define ERR_RANGE 3

#define LEN_STR 20
#define MAX_LEN 256
#define MAX_N 40

struct birthday_t
{
	int day;
	int month;
	int year;
};
struct office_t
{
    char work[LEN_STR + 1];
	char organization[LEN_STR + 1];
};
struct contact_t
{
   char family[LEN_STR + 1];
   char name[LEN_STR + 1];
   char number[LEN_STR + 1];
   char address[LEN_STR + 1];
   int type;
   union
   {
        struct birthday_t birthday;
        struct office_t office;
   };
};
struct list_t
{
    struct contact_t data;
    int index;
};

#endif // _APP_H_
