#include<stdio.h>
int main()
{
    int t, i=1, m, n, temp,count;
    scanf("%d", &t);
    while(i<=t)
    {
        scanf("%d %d", &m, &n);
        if(m<n)
        {
            temp=m;
            m=n;
            n=temp;
        }
        if(m==1||n==1)
        count=m;
        else if(m==2||n==2)
        {
            count=(m/4)*4;
            if(m%4==1)
                count+=2;
            else if(m%4>1)
                count+=4;
        }
        else
            count=(m*n+1)/2;
        printf("Case %d: %d\n", i, count);
        i++;

    }

}
