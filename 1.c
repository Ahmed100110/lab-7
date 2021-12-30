#include <pthread.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int carry = 0;
void *craeteRandomThread(void *param)
{
    int x = rand();
    int myNum = *((int *)param);
    printf("thread %i", myNum);
    printf(" >> Random %d\n", x % 10 + 1);
    carry += x % 10 + 1;
}
void *sum(void *param)
{
    printf("sum = %i\n", carry);
}
int main()
{
    int *arr;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;
    pthread_t total, thread_1, thread_2, thread_3, thread_4;
    pthread_create(&thread_1, 0, craeteRandomThread, &arr[0]);
    pthread_join(thread_1, 0);
    pthread_create(&thread_2, 0, craeteRandomThread, &arr[1]);
    pthread_join(thread_2, 0);
    pthread_create(&thread_3, 0, craeteRandomThread, &arr[2]);
    pthread_join(thread_3, 0);
    pthread_create(&thread_4, 0, craeteRandomThread, &arr[3]);
    pthread_join(thread_4, 0);
    pthread_create(&total, 0, sum, 0);
    wait(pthread_join(total, 0));
}