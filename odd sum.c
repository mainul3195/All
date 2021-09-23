#include<stdio.h>
int main()
{
    int t, i=1, n,a,b, j, sum;
    scanf("%d", &t);
    while(i<=t)
    {
        sum=0;
        scanf("%d %d", &a, &b);
        for(j=a;j<=b;j++)
            {
                if(j%2==1)
                    sum+=j;
            }
            printf("Case %d: %d\n", i, sum);
            i++;
    }
    return 0;
}
