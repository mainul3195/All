#include<stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x, n, temp,count=0, i,arr[300]={0};
        scanf("%d %d", &n, &x);
        for(i=1; i<=n; i++)
        {
            scanf("%d", &temp);
            arr[temp]=1;
        }
        for(i=1;arr[i]==1||x>0;i++ )
        {
            if(arr[i]==0)
                x--;
        }
        printf("%d\n", i-1);
    }
    return 0;
}
