#include<stdio.h>
int main()
{
    char Person[300][50];
    int n,expendeture[300],i, total=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", Person[i]);
        scanf("%d", &expendeture[i]);
        total+=expendeture[i];
    }
    printf("\n\nSl No\tPerson                                                   Taka\n");
    printf("-------------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        printf("%03d\t%-50s%9d\n", i+1, Person[i], expendeture[i]);
    }
    printf("-------------------------------------------------------------------\n");
    printf("    \tTotal                                             %9d\n", total);
    return 0;
}
