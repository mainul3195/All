
#include<stdio.h>
int main()
{
    int i=1, t;
    long long k, a,temp, j ,d, b[4], n[4];
    scanf("%d", &t);
    while(i<=t)
    {
        scanf("%lld.%lld.%lld.%lld %lld.%lld.%lld.%lld",&n[0],&n[1], &n[2], &n[3], &b[0], &b[1], &b[2], &b[3]);
        k=0;
        for(temp=b[k]; k<4; temp=b[k])
        {
            j=1;
            d=0;

            while(temp!=0)
            {
                d+=(temp%10)*j;
                temp/=10;
                j*=2;
            }
            if(n[k]!=d)
                break;
            k++;
        }

        if(k==4)
            printf("Case %d: Yes\n", i);
        else
            printf("Case %d: No\n", i);
        i++;

    }
    return 0;
}
