#include<stdio.h>
void execute()
{
    long long a,b,n,c;
    int i;
    scanf("%lld %lld %lld", &a, &b, &n);
    if(a>b)
    {
        c=a;a=b;b=c;
    }
    c=a+b;
    for(i=1; c<=n; i++)
    {
        a=b; b=c; c=a+b;
    }
    printf("%d\n", i);
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