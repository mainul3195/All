#include<stdio.h>
#include<math.h>
double loggi[1000002];

int main()
{
    int t, i, j;
    scanf("%d", &t);
    loggi[0]=0.0;
    for(j=1;j<1000002; j++)
        loggi[j]=loggi[j-1]+log(j);


    for(i=1; i<=t; i++)
    {
        int n, base;
        long long digit;
        scanf("%d %d", &n, &base);
        digit=floor(loggi[n]/log(base))+1;
        printf("Case %d: %lld\n", i, digit);
    }

    return 0;
}
