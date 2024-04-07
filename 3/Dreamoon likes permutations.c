#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int num[200010],test[200010]={0}, prnt=0,n,max=0, i,ft[100005]= {0};
        scanf("%d", &n);
        for(i=1; i<=n; i++)
        {
            scanf("%d", &num[i]);
            test[num[i]]++;
            if(num[i]>max)
                max=num[i];
        }
        if(max<ceil((n/2.0)))
        {
            printf("0\n");
            continue;
        }
        else
        {
            for(i=1; i<=n-max; i++)
                if(test[i]!=2)
                    goto mainul;
            for(i=n-max+1; i<=max; i++)
                if(test[i]!=1)
                    goto mainul;

            for(i=1; i<=n-max; i++)
            {
                ft[num[i]]++;
            }
            for(i=1; i<=n-max; i++)
            {
                if(ft[i]!=1)
                {
                    break;
                }
            }
            if(i==n-max+1)
                prnt++;
            for(i=1; i<=n-max; i++)
            {
                ft[num[i]]=0;;
            }
            for(i=n; i>max; i--)
            {
                ft[num[i]]++;
            }
            for(i=n-1; i>=max; i--)
            {
                if(ft[n-i]!=1)
                {
                    break;
                }
            }
            if(i==max-1)
                prnt++;

            if(prnt==1)
                printf("1\n%d %d\n", n-max, max);
            if(prnt==2)
                printf("2\n%d %d\n%d %d\n", n-max, max,max,n-max);
                mainul:
            if(prnt==0)
                printf("0\n");
        }
    }
    return 0;

}
