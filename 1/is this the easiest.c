
#include<stdio.h>
int main()
{
    long long t, i=1, n,a,b,c, j, sum;
    scanf("%lld", &t);
    while(i<=t)
    {
        sum=0;
        scanf("%lld %lld %lld", &a, &b, &c);
        if((a+b>c)&&(b+c>a)&&(c+a>b))
        {
            if(a==b&&b==c)
                printf("Case %lld: Equilateral\n", i);
            else if((a==b&&a!=c)||(b==c&&b!=a)||(c==a&&c!=b))
                printf("Case %lld: Isosceles\n", i);
            else
                printf("Case %lld: Scalene\n", i);
        }
        else
            printf("Case %lld: Invalid\n", i);

            i++;


    }
    return 0;
}
