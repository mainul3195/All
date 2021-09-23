#include<stdio.h>
int main()
{
    int i, t,j,k,flag;
    long long p,l,x,ml[1200], lim;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        flag=0;
        scanf("%lld %lld", &p, &l);
        x=p-l;

        for(p=1, k=0; p*p<=x; p++)
        {
            if(x%p==0)
            {
                ml[k++]=p;
                ml[k++]=x/p;
            }
        }

        printf("Case %d:", i);
        for(j=0; j<k; j+=2)
        {
            if(ml[j]>l)
            {
                flag=1;
                printf(" %lld", ml[j]);
            }
        }
        j--;
        if(ml[j]==ml[j-1])
            j-=2;
        while(j>=0)
        {
            if(ml[j]>l)
            {
                flag=1;
                printf(" %lld", ml[j]);
            }
            j-=2;
        }
        if(flag==0)
            printf(" impossible");
        puts("");
    }

}
