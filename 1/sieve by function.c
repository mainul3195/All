#include<stdio.h>
#include<math.h>
int array[110000000],c,prime[110000000],i,j,n, limit;

void seive(int);


int main()
{
    scanf("%d", &n);
    seive(n);
    return 0;
}

void seive(int n)
{
    limit=sqrt(n);
    for(i=3; i<=limit; i+=2)
        if(!array[i])
            for(j=i*i; j<=n; j+=i+i)
                array[j]=1;
    prime[c++]=2;
    for(i=3; i<=n; i+=2)
        if(!array[i])
            prime[c++]=i;
//    for(i=0; i<c; i++)
//        printf("%d%c", prime[i], ",\n"[i==c-1]);

        printf("%d", c);
}

