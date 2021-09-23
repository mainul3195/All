#include<stdio.h>
int main()
{
    char name[300][50];
    int n,cost[300],i, sum=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", name[i]);
        scanf("%d", &cost[i]);
        sum+=cost[i];
    }
    printf("\n\nSl No\tName                                                   Taka\n");
    printf("-------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf("%03d\t%-50s%9d\n", i+1, name[i], cost[i]);
    }
    printf("-------------------------------------------------------------------\n");
    printf("    \tTotal                                             %9d\n", sum);
    return 0;
}
