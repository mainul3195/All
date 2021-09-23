
#include<stdio.h>
int main()
{
    int t,n, a, b;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        a=n/2;
        b=n-a;
        printf("%d %d\n", a,b);
    }
    return 0;
}
