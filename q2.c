#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
int main()
{
    int shmid = shmget(1234, sizeof(int), 0666 | IPC_CREAT);
    int *shared_variable = (int *)shmat(shmid, NULL, 0);
    pid_t p1 = fork();
    if (p1 == 0)
    {
        int shmid = shmget(1234, sizeof(int), 0666);
        int *shared_variable = (int *)shmat(shmid, NULL, 0);
        printf("This is the first thread with id %d and the value of shared variable is %d\n", getpid(), *shared_variable);
    }
    else
    {
        pid_t p2 = fork();
        if (p2 == 0)
        {
            int shmid = shmget(1234, sizeof(int), 0666);
            int *shared_variable = (int *)shmat(shmid, NULL, 0);
            printf("This is second thread with id %d and the value of shared variable is %d\n", getpid(), *shared_variable);
        }
        else
        {
            printf("We are in parent process and updating the value...\n");
            *shared_variable = 42;
            print("Terminating\n");
        }
    }
    return 0;
}