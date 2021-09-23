#include<stdio.h>
int main()
{
    int t, i;
    long long j, n, count;;
    double test;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        count=0;
        scanf("%lld", &n);
        for(j=1;(j*(j+1))<2*n; j++)
        {
            test=(1.0*n-(j*(j+1))/2)/(j+1);
            if(test-(int)test==0.0)
                count++;
        }
        printf("Case %d: %lld\n", i, count);

    }
    return 0;
}
