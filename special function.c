#include<stdio.h>
#include<math.h>
int main()
{
    long long a,t;
    scanf("%lld", &a);
    if(a==0)
        printf("0\n");
    else{
        t=ceil((double)a/2);
        if(a%2==0)
            printf("%lld\n", t);
        else
            printf("%lld\n", -t);
    }

}
