#include<stdio.h>

int d2b(int n)
{
    int b=0, j=1;
    while (n!=0)
    {
        b+=(n%2)*j;
        n/=2;
        j*=10;
    }
    return b;
}
int main()
{
    int d1,d2,d3,d4,b1,b2,b3,b4,t1, t2, t3, t4, i,t;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d.%d.%d.%d %d.%d.%d.%d", &d1, &d2, &d3, &d4, &b1, &b2, &b3, &b4);
         t1 = d2b(d1);
         t2 = d2b(d2);
         t3 = d2b(d3);
         t4 = d2b(d4);

        if(t1==b1&&t2==b2&&t3==b3&&t4==b4)
        {
            printf("Case %d: Yes\n",i);
        }
        else
            printf("Case %d: No\n",i);

    }
    return 0;
}


