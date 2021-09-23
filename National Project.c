#include<stdio.h>

typedef long long int lli;
int main()
{
    lli td,t, g, b,i, n, mg,bt, count,bad;
    scanf("%lld", &t);
    for(i=0; i<t; i++)
    {
        td=0;
        scanf("%lld %lld %lld", &n, &g, &b);

        if(n%2==0)
            mg=n/2;
        else
            mg=(n/2)+1;

        bt=n-mg;
        count=mg/g;
        td=count*g;
        if(mg%g!=0)
        {
            td+=(mg%g);
            count++;
        }
        bad=(count-1)*b;
        if(bt<bad)
            td+=bad;
        else
            td+=bt;

        printf("%lld\n", td);

    }

    return 0;
}
