#include<stdio.h>
int main()
{
    int t, n, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        if((k*k)<=n)
        {
            if((n%2==0&&k%2==0)||(n%2==1&&n%2==1))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
