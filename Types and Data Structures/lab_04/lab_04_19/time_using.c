#include "time_using.h"

unsigned long long tick(void)
{
    unsigned long long time;
    __asm__ __volatile__ ("rdtsc" : "=A" (time));
    return time;
}
void time_using(int N)
{
    //Array stack
    int size = 0;
    unsigned long long time_b, time_e, time;
    printf("Array Stack:\n");
    char **array = calloc(N, sizeof(char *));
    for (int i =0; i < N; i++)
        array[i] = calloc(MAX + 1, sizeof(char));
    char **pcur = array - 1;
    time_b = tick();
    for (int i = 0; i < N; i++)
    {
        push_array_2(&pcur, array + N - 1, "xx");
        size += sizeof(array[i]);//strlen(array[i]);
    }
    for (int i = 0; i < N; i++)
    {
        pop_array_2 (&pcur, array);
    }
    time_e = tick();
    time = time_e - time_b;
    //size += sizeof(array) + sizeof(pcur);
    printf("Size         : %d\n", size);
    printf("Time running : %llu\n", time);
    free_array(array, N);
    //List stack
    printf("List stack:\n");
    struct list_t *head = NULL;
    size = 0;
    time_b = tick();
    for (int i = 0; i < N; i++)
    {
        head = push_list(head, "xx");
    }
    printf("Push\n");
    size = sizeof(head) * N;
    for (int i = 0; i < N; i++)
    {
        head = pop_list(head);
    }
    free_list(head);
    time_e = tick();
    time = time_e - time_b;
    printf("Size         : %d\n", size);
    printf("Time running : %llu\n", time);//Нгуен Ань Тхы
}
