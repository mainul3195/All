
#include<stdio.h>
#include<math.h>

int array[110],c,prime[100];

int main()
{
    int main_number, stored_number;
    int  count,i,j,prime_limit, star, t, k=1;



    for(i=3; i<=10; i+=2)
        if(!array[i])
            for(j=i*i; j<=100; j+=i+i)
                array[j]=1;

    prime[c++]=2;
    for(i=3; i<=100; i+=2)
        if(!array[i])
            prime[c++]=i;

            scanf("%d", &t);
    while(k<=t)
    {
        scanf("%d", &main_number);
        star=0;

        prime_limit=sqrt(main_number);
        stored_number=main_number;

        for(i=0; prime[i]<=prime_limit; i++)
        {
            if(main_number%prime[i]==0)
            {
                count=0;
                while(main_number%prime[i]==0)
                {
                    count++;
                    main_number/=prime[i];
                }
                printf("Cade %d: %d =%c %d (%d) ",i,stored_number, "*"[star++==0], prime[i], count);
                if(main_number==1)
                    break;
            }
        }

        if(main_number!=1)
            printf("%c %d (1)","*"[star++==0], main_number);
        puts("");
        k++;
    }

    return 0;
}
