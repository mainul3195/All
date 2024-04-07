#include<stdio.h>
void execute()
{
    int i,n;
    scanf("%d", &n);
    if(n%2) n--;
    printf("%d\n", n/2);
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
        execute();
    return 0;
}