#include "time_testing.h"

#define LINE 96

void write_on_file(int N)
{
    FILE *f;
    f = fopen(FILE_NAME, "w");
    srand(time(NULL));
    int num;
    for (int i = 0; i < N; i++)
    {
        num = rand() % N;
        fprintf(f, "%d ", num);
    }

    fclose(f);
}

int find_in_file(int value)
{
    int size = 0;
    FILE *f;
    int num;
    f = fopen(FILE_NAME, "r");
    while(fscanf(f, "%d", &num) == 1)
    {
        size += sizeof(num);
        if (num == value)
            return size;
    }
    fclose(f);
    return size;
}
void print_line(void)
{
    for (int i = 0; i < LINE; i++)
        printf("-");
    printf("\n");
}

unsigned long long tick(void)
{
    unsigned long long time;
    __asm__ __volatile__ ("rdtsc" : "=A" (time));
    return time;
}

void time_test(int N)
{
    int value = 39;
    struct node_t *tree = NULL;
    struct node_t *root = NULL;

    unsigned long long time_begin, time_end;
    unsigned long long time1, time2, time3, time4;
    int size1, size2, size3, size4;

    write_on_file(N);
    FILE *f;
    f = fopen(FILE_NAME, "r");
    read_file(f, &root, &tree);
    fclose(f);

    time_begin = tick();

    find_node(root, value);

    time_end = tick();

    time1 = time_end - time_begin;
    size1 = sizeof(struct node_t) * N;
    //printf("Balance Tree: \n");
    //printf("Time  : %I64d\n", time);
    //printf("Memory: %d\n", size);

    time_begin = tick();

    find_node(tree, value);

    time_end = tick();

    time2 = time_end - time_begin;
    size2 = sizeof(struct node) *N;
    //printf("Normal tree: \n");
    //printf("Time  : %I64d\n", time);
    //printf("Memory: %d\n", size);

    struct data_t* a[SIZE];
    FILE *f1;
    f1 = fopen(FILE_NAME, "r");
    creat_array(f1, a);
    fclose(f1);

    time_begin = tick();

    find_in_table(a, value);

    time_end = tick();

    time3 = time_end - time_begin;
    size3 = sizeof(struct data_t) * N;
    //printf("Hash table:\n");
    //printf("Time  : %I64d\n", time);
    //printf("Memory: %d\n", size);

    time_begin = tick();

    size4 = find_in_file(value);

    time_end = tick();

    time4 = time_end - time_begin;
    //printf("Find in file:\n");
    //printf("Time  : %I64d\n", time);
    //printf("Memory: %d\n", size);

    print_line();
    printf("|%10s|%20s|%20s|%20s|%20s|\n", "", "Balance Tree", "Normal Tree", "Hash Table", "Find In File");
    print_line();
    printf("|%10s|%20I64d|%20I64d|%20I64d|%20I64d|\n", "Time", time1, time2, time3, time4);
    print_line();
    printf("|%10s|%20d|%20d|%20d|%20d|\n", "Memory", size1, size2, size3, size4);
    print_line();
}
