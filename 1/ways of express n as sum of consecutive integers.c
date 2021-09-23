#include<stdio.h>
#include<math.h>
int prime[1280000],c,count[1280000]={0},cnt;
char arr[20000001];
int main()
{
    int t,j,k,i=1;
    long long b,n,d, a=0,lim, mul;

    scanf("%d", &t);
    for(j=3; j<=4473; j+=2)
        if(!arr[j])
            for(k=j*j; k<=20000000; k+=j+j)
                arr[k]=1;
    prime[c++]=2;
    for(j=3; j<=20000000; j+=2)
        if(!arr[j])
            prime[c++]=j;
    while(t--)
    {
        for(j=0; j<=a; j++)
            count[j]=0;
        scanf("%lld", &b);
        n=2*b;
        lim=sqrt(n);
        for(a=0; prime[a]<=lim; a++)
        {
            cnt=0;
            while(n%prime[a]==0)
            {
                cnt++;
                n/=prime[a];
            }
            count[a]=cnt;
            if(n==1)
            {
                a++;
                break;
            }
        }
        if(n!=1)
            count[a]++;
        for(d=1, mul=1; d<=a; d++)
            mul*=(count[d]+1);
        printf("Case %d: %lld\n", i++, mul-1);

    }

    return 0;
}
