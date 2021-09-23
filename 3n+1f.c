#include<stdio.h>
int main()
{
    long long x,y,start, n,end,count,temp, max,i;

    while(scanf("%lld %lld", &start, &end)!= EOF)
    {

    x=start;
    y=end;
    if(start>end)
    {
        temp=start;
        start=end;
        end=temp;
    }

    max=0;

        for(i=start; i<=end; i++)
        {
            n=i;
            count=1;
            while(n!=1)
            {
                count++;

                if(n%2==1)
                    n=3*n+1;
                else
                    n/=2;
            }

            if(count>max)
                max=count;
        }
        printf("%lld %lld %lld\n",x,y, max );
    }
    return 0;
}
