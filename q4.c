#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#define buffer_size 5
sem_t s;
int counter = 0;
int in = 0;
int out = 0;
int i;
int buffer[buffer_size];
void *producer()
{
    while (1)
    {
        while (counter == buffer_size)
            ;
        sem_wait(&s);
        int item_produced = rand() % 100;
        printf("Item %d is produced\n", item_produced);
        buffer[in] = item_produced;
        in = (in + 1) % buffer_size;
        counter++;
        for (i = 0; i < buffer_size; i++)
            printf("%d%c", buffer[i], " \n"[i == buffer_size - 1]);
        sem_post(&s);
    }
}
void *consumer()
{
    while (1)
    {
        while (counter == 0)
            ;
        sem_wait(&s);
        int next_consumed = buffer[out];
        printf("Item %d is consumed\n", next_consumed);
        buffer[out] = -1;
        out = (out + 1) % buffer_size;
        counter--;
        for (i = 0; i < buffer_size; i++)
            printf("%d%c", buffer[i], " \n"[i == buffer_size - 1]);
        sem_post(&s);
    }
}
int main()
{
    for (i = 0; i < buffer_size; i++)
        buffer[i] = -1;
    sem_init(&s, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, producer, NULL);
    pthread_create(&thread2, NULL, consumer, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}