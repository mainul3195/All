#include<stdio.h>
int main()
{
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(n==0)
            return 0;
        if(n>=101)
            printf("f91(%d) = %d\n", n, n-10);
        else
            printf("f91(%d) = 91\n", n);
    }
}
