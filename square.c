#include<stdio.h>
int main()
{
    int n,i,r, m;
    while(~scanf("%d", &n))
    {
        for (r=1; r<=n; r++)
        {

            for(i=1; i<=n; i++)
            {
                if(r==1||r==n||i==n||i==1)
                    printf("*");
                else
                    printf(" ");
            }


            puts("");
        }
    }
    return 0;
}

