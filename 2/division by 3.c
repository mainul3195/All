#include<stdio.h>
int main()
{
    int t, i=1, j,count,a,temp,b,upvalue, lowvalue;

    scanf("%d", &t);
    while(i<=t)
    {
        count=0;

        scanf("%d %d", &a, &b);

        lowvalue=((a-1)/3)*2;
        if((a-1)%3==2)
            lowvalue++;

        upvalue=(b/3)*2;
        if(b%3==2)
            upvalue++;

            printf("Case %d: %d\n", i, upvalue-lowvalue);
            i++;
    }
    return 0;
}

