#include<stdio.h>
#include<math.h>

int array[11000000],c,prime[1000000];

int main()
{
    long long int main_number, stored_number;
    int  i,j,prime_limit, seive_limit;

    while(~(scanf("%lld", &main_number)))
    {

        prime_limit=sqrt(main_number);
        seive_limit=sqrt(prime_limit);

        for(i=3; i<=seive_limit; i+=2)
            if(!array[i])
                for(j=i*i; j<=prime_limit; j+=i+i)
                    array[j]=1;

        prime[c++]=2;
        for(i=3; i<=prime_limit; i+=2)
            if(!array[i])
                prime[c++]=i;

        prime[c]=0;
        stored_number=main_number;

        for(i=0; prime[i]!=0;)
        {
            if(main_number%prime[i]==0)
            {
                printf("%d ", prime[i]);
                main_number/=prime[i];
                if(main_number==1)
                    break;
            }
            else
                i++;

        }
        if(main_number!=1)
            printf("%lld", main_number);
        puts("");
    }

    return 0;
}
