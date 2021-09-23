#include<stdio.h>
int array[10010],c, count,dividor[1250], temp, mul[4000];
void reverse(void)
{
    if(mul[count+1]!=20)
    {
        count++;
        reverse();
    }

    printf("%d", mul[count]);
    count--;
    return;
}
int main()
{
    int t, k,i,p=1,j,l,m, number[1000],n,rem,carry, prime[1250], sec[4000], num,kmax;
    int limit=100;

    for(i=3; i<=limit; i+=2)
        if(!array[i])
            for(j=i*i; j<=10000; j+=i+i)
                array[j]=1;

    prime[c++]=2;
    for(i=3; i<=10000; i+=2)
        if(!array[i])
            prime[c++]=i;

    for(i=0; i<4000; i++)
    {
        mul[i]=sec[i]=20;
    }

    scanf("%d", &t);
    while(p<=t)
    {
        if(p!=1)
        {
            count=0;
            for(m=0; mul[m]!=20; m++)
            {
                mul[m]=20;
            }
        }
        mul[0]=1;

        scanf("%d", &n);
        for(j=0; j<n; j++)
            scanf("%d", &number[j]);
        kmax=0;
        for(j=0; j<n; j++)
        {
            k=0;
            while(number[j]!=1)
            {
                temp=0;
                while(number[j]%prime[k]==0)
                {
                    temp++;
                    number[j]/=prime[k];
                }
                if(temp>dividor[k])
                    dividor[k]=temp;
                k++;
            }
            if(k>kmax)
                kmax=k;
        }
        for(j=0; j<kmax; j++)
        {
            num=l=0;
            for(k=dividor[j]; k>0; k--)
                num+=prime[j];
            dividor[j]=0;
            while(num!=0)
            {
                rem=num%10;
                num/=10;
                carry=m=0;
                k=l++;
                do
                {
                    temp=sec[k]%10+rem*(mul[m]%10)+carry;
                    sec[k]=temp%10;
                    carry=temp/10;
                    k++;
                    m++;
                }
                while(carry!=0||mul[m]!=20);
            }
            for(m=0; sec[m]!=20; m++)
            {
                mul[m]=sec[m];
                sec[m]=20;
            }
        }
        printf("Case %d: ", p);
        reverse();
        puts("");
        p++;
    }
    return 0;
}
