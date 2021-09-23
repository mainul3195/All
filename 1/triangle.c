#include<stdio.h>
int main()
{
    int n,i,r, m;
    while(~scanf("%d", &n))
    {
        m=n;
        for (r=1; r<=n; r++)
        {

            for(i=1; i<=m; i++)
            {
                if(r+i==n+1||i-r==n-1||r==n)
                    printf("*");
                else
                    printf(" ");
            }
                m++;


            puts("");
        }
    }
    return 0;
}
