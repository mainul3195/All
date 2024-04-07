#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t p1 = fork();
    if (p1 == 0)
    {
        printf("S1\n");
    }
    else
    {
        wait(NULL);
        pid_t p2 = fork();
        if (p2 == 0)
        {
            printf("S2\n");
        }
        else
        {
            waitpid(p1, NULL, 0);
            waitpid(p2, NULL, 0);
            printf("Done\n");
        }
    }
    return 0;
}