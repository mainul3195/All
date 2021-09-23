#include<stdio.h>
#include<math.h>
int array[400000000],c,number,prime[110000000];
int main()
{
    int  i,j,n=4000000000, k=0,limit;


    c=0;
    limit=sqrt(n);
    for(i=3; i<=limit; i+=2)
        if(!array[i])
            for(j=i*i; j<=n; j+=i+i)
                array[j]=1;
    prime[c++]=2;
    for(i=3; i<=n; i+=2)
        if(!array[i])
            prime[c++]=i;

    while(scanf("%d", &number)!=EOF)
    {
        int count=0, k=0;
        while(1)
        {
            if(prime[k]==prime[k+1]-2)
                count++;
             if(count==number)
                 break;

             k++;


        }
        printf("(%d, %d)\n", prime[k], prime[k+1]);
    }


    return 0;
}
