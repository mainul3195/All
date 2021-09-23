#include<stdio.h>
int main()
{
    long long b,n,count,j,i,r;
    char binary[50];
    while(1)
    {
        scanf("%lld", &n);
        if(n==0)
            return 0;
        for(i=1;i<=n; i*=2);
        i/=2;
        j=0;
        count=0;
        while(i!=0)
        {
            if(n>=i)
            {
                binary[j]='1';
                count++;
                n-=i;
            }
            else
                binary[j]='0';
            i/=2;
            j++;
        }
        binary[j]='\0';

        printf("The parity of %s is %lld (mod 2).\n", binary,count);

    }
}
