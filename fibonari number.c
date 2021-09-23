#include<stdio.h>
#include<string.h>

int main()
{
    char num1[101], num2[101], fin[101];
    int  i, j, length1, length2;
    long long fibonacci[101];
    long double sum=0, number1, number2;
    fibonacci[0]=1;
    fibonacci[1]=2;
    for(i=2; i<101; i++)
        fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
        for(j=0; j<91; j++)
            sum+=fibonacci[j];
        printf("%llf", sum);
   /* while((scanf("%s %s", num1, num2))!=EOF)
    {
        number1=number2=0;
        length1=strlen(num1)-1;
        length2=strlen(num2)-1;
        for(j=0,i=length1; i>=0; j++,i--)
        {
            if(num1[i]=='1')
                number1+=fibonacci[j];

        }

        for(j=0,i=length2; i>=0; j++,i--)
        {
            if(num1[i]=='1')
                number2+=fibonacci[j];

        }

        sum=number1+number2;
        for(i=0; sum>=fibonacci[i]; i++);
        i--;

        for(j=0;i>=0; j++,i--)
        {
            if(sum>=fibonacci[i])
            {
                sum-=fibonacci[i];
                fin[j]='1';
            }
            else
                fin[j]='0';
          }
          fin[j]='\0';
        printf("%s\n\n",fin);
    }*/


}
