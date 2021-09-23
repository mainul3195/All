#include<stdio.h>

int main()
{
    int   n;
    long long fact;
    while((scanf("%d", &n))!=EOF)
    {
        for(fact=1; n>=1; n--)
        {
            fact*=n;
            if(fact>6227020800)
            {

                break;
            }
        }
        if(fact<10000)
            printf("Underflow!\n");
        else if(fact>6227020800)
            printf("Overflow!\n");
        else
        printf("%lld\n", fact);
    }
    return 0;

}
