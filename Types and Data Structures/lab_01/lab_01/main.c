#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_MN 30
#define MAX_LEN 60
#define MAX_K 99999
#define OK 0
#define ERR -1
int check_float(char *a)
{
    int n = strlen(a);

    int symbol = 0, point = 0, e = 0;
    char *number = "0123456789";
    for (int i = 0; i < n; i++)
    {
        if (symbol && (a[i] == '+' || a[i] == '-'))
            return ERR;
        else if (a[i] == '.' && point)
            return ERR;
        else if (a[i] == 'e' && e)
            return ERR;
        else if (a[i] == '+' || a[i] == '-')
            symbol = 1;
        else if (a[i] == '.')
            point = 1;
        else if (a[i] == 'e')
        {
            e = 1;
            symbol = 0;
        }
        else if (memchr(number, a[i], strlen(number)) == NULL)
            return ERR;
    }
    return OK;
}
int check_int(char *a)
{
    int n = strlen(a);
    char *number = "0123456789";
    if (a[0] != '+' && a[0] != '-' && (memchr(number, a[0], strlen(number)) == NULL))
        return ERR;
    for (int i = 1; i < n; i++)
    {
        if (memchr(number, a[i], strlen(number)) == NULL)
            return ERR;
    }

    return OK;
}
int float_to_int(char *a, int *b, int *n, int *power, int *symbol)
{
    int i = 0, len = strlen(a);
    *symbol = 1;
    *power = 0;
    if (a[i] == '+' || a[i] == '-')
    {
        if (a[i] == '-')
            *symbol = -1;
        i++;
    }
    *n = 0;
    char *number = "0123456789";
    while (i < len && (memchr(number, a[i], strlen(number)) != NULL))
    {
        b[*n] = a[i] - '0';
        (*n)++;
        i++;
    }
    if (i < len && a[i] == '.')
    {
        i++;
        while(i < len && memchr(number, a[i], strlen(number)) != NULL)
        {
            b[*n] = a[i] - '0';
            (*n)++;
            i++;
            *power -=1;
        }
    }
    if ((*n) > MAX_MN)
        return ERR;
    char c[6];
    if (i < len && a[i] == 'e')
    {
        i++;
        if (len - i > 6)
            return ERR;
        strncpy(c, a + i, len - i + 1);
        *power += atoi(c);
        if (*power > MAX_K)
            return ERR;
    }

    return OK;
}
void swap_array(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}
void copy_array(int *a, int beg, int end, int *b)
{
    for (int i = 0; i < end - beg + 1; i++)
    {
        b[i] = a[i + beg];
    }
}
void sub(int *a, int len_a, int *b, int len_b)
{
    int c[MAX_MN];
    int len_c = len_a;
    int remember = 0;
    int temp = 0;
    for (int i = 1; i <= len_c; i++)
    {
        if (len_b - i >= 0)
            temp = a[len_a - i] - b[len_b - i] - remember;
        else
            temp = a[len_a - i] - remember;
        if (temp < 0)
        {
            temp += 10;
            remember = 1;
        }
        else
            remember = 0;
        c[len_c - i] = temp;
    }
    copy_array(c, 0, len_c, a);
}
int compare(const int *a, int len_a, const int *b, int len_b)
{
    if (len_b > len_a)
        return 0;
    if (len_a > len_b)
        return 1;
    for (int i = 0; i < len_b; i++)
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return 0;
    }

    return 1;
}
void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d",a[i]);
}
void format(int *x,int *len_x)
{
    int i;
    while ((*len_x  > 0) && x[0] == 0)
    {
        i = 0;
        while (i < *len_x - 1)
        {
            x[i] = x[i + 1];
            i++;
        }
        (*len_x)--;
    }
}
int divide(int *a, int len_a, int *b, int len_b, int *c, int *len_c, int pow)
{
    *len_c = MAX_MN;
    int x[MAX_MN];
    int end = len_b, len_x = len_b;
    while (len_a < len_b)
    {
        a[len_a] = 0;
        len_a ++;
        pow--;
    }
    copy_array(a, 0, len_x, x);
    int res;
    for (int i = 0; i < *len_c; i++)
    {
        if (end < len_a)
            pow++;
        while (end >= len_a)
        {
            a[len_a] = 0;
            len_a++;
        }
        format(x, &len_x);
        if (!compare(x, len_x, b, len_b))
        {
            x[len_x] = a[end];
            end++;
            len_x++;
            //pow--;
        }
        //print_array(x, len_x);
        //printf("\n");
        res = 0;
        while (compare(x, len_x, b, len_b))
        {
            //printf("compare: %d\n", compare(x, len_x, b, len_b));
            res++;
            sub(x, len_x, b, len_b);
            format(x, &len_x);
            //print_array(x, len_x);
            //printf("\n");
        }
        //printf("res = %d\n", res);
        c[i] = res;
    }
    return pow;
}
int main(void)
{

    char num_a[MAX_LEN];
    char num_b[MAX_LEN];
    int c[MAX_LEN];
    int a[MAX_LEN];
    int b[MAX_LEN];
    int rc = OK, len_a, len_b, len_c;
    int powa, powb, pow, symbola, symbolb;
    printf("                              /------------------------------\n");
    printf("input int number (len <= 30): ");
    if (!gets(num_a))
        rc = ERR;
    //printf("check numa: %d\n",check_int(num_a));
    printf("                               /------------------------------e/-----\n");
    printf("input float number +-M.Ne+-K : ");
    if (!gets(num_b))
        rc = ERR;
    //printf("check numb: %d\n", check_float(num_b));
    if (rc == OK)
        rc = check_int(num_a);
    if (rc == OK)
        rc = check_float(num_b);
    if (rc == OK)
        rc = float_to_int(num_a, a, &len_a, &powa, &symbola);
    if (rc == OK)
        rc = float_to_int(num_b, b, &len_b, &powb, &symbolb);
    if (rc == ERR)

        printf("Error input\n");
    if (rc == OK)
    {
        format(a, &len_a);
        format(b, &len_b);
        if (b[0] == 0)
        {
            rc = ERR;
            printf("Error division by zero\n");
        }
        if (a[0] == 0)
        {
            rc = ERR;
            printf("result = +0e+0\n");
        }
    }
    if (rc == OK)
    {
        pow = divide(a, len_a, b, len_b, c, &len_c, -powb);
    }
    if (abs(pow) > MAX_K)
    {
        rc = ERR;
        printf("pow > 5 number\n");
    }
    if (rc == OK)
    {
        printf("\nresult = ");
        if (symbola *symbolb < 0)
            printf("-0.");
        else
            printf("+0.");
        while (c[len_c - 1] == 0 && len_c > 0)
        {
            len_c--;
        }
        print_array(c, len_c);
        if (pow >= 0)
            printf("e+");
        else
            printf("e");
        printf("%d\n", pow);
    }


    return rc;
}
