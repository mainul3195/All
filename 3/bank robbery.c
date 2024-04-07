#include<stdio.h>

int main()
{
    int i, t;
    scanf("%d", &t);
    unsigned long long n,x;
    for(i=1; i<=t; i++)
    {
        scanf("%llu", &n);
        printf("Case %d:", i);
        x=(n*10)/9;
        x--;
        if(x-(x/10)==n)
            printf(" %llu", x);
        x++;
        if(x-(x/10)==n)
            printf(" %llu", x);
        x++;
        if(x-(x/10)==n)
            printf(" %llu", x);
        puts("");

    }
    return 0;
}
