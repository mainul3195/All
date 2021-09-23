#include<stdio.h>
int main()
{
    int i, t, n, j,k,c,prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        int array[102]={0};
        scanf("%d", &n);
        for(j=2; j<=n; j++)
        {
            for(k=j,c=0;k!=1;)
            {
                if(k%prime[c]==0)
                {
                    array[prime[c]]++;
                    k/=prime[c];
                }
                else
                    c++;
            }
        }

        printf("Case %d: %d =", i, n);
        for(j=0; prime[j]<=n; j++)
        {
            if(array[prime[j]]!=0){
                printf(" %d (%d)", prime[j],array[prime[j]] );
                break;
            }
        }
        for(j++; prime[j]<=n; j++)
        {
            if(array[prime[j]]!=0){
                printf(" * %d (%d)", prime[j],array[prime[j]] );

            }
        }
        puts("");
    }
}
