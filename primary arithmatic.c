#include<stdio.h>
int main()
{
    long long num1, num2,r1,r2;
    int count, carry;
    while(1)
    {
        scanf("%lld %lld", &num1, &num2);
        if(num1==0&&num2==0)
            return 0;
        count=0;
        carry=0;
        while(num1!=0||num2!=0)
        {
            r1=num1%10;
            r2=num2%10;
            num1/=10;
            num2/=10;
            if((carry+r1+r2)>9){
                count++;
                carry=(carry+r1+r2)/10;}
                else
                    carry=0;
        }
        if(count==0)
            printf("No carry operation.\n");
        else if(count==1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", count);

    }
}
