#include<stdio.h>
int main()
{
    int t, a, b, c, n, r,k,i, l,result[10000];
    scanf("%d", &t);

    for(i=0; i<t; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &n);
        if(a>=b&&a>=c)
            l=a;
        else if(b>=a&&b>=c)
            l=b;
        else
            l=c;

        r=(l-a)+(l-b)+(l-c);
        k=n-r;
        if(k>=0&&k%3==0)
            result[i]=1;
        else
            result[i]=0;
    }
     for(i=0; i<t; i++)
     {
         if(result[i]==1)
            printf("YES\n");
         else
            printf("NO\n");
     }

     return 0;
}
