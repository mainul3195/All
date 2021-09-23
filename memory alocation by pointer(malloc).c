#include<stdio.h>
#include <stdlib.h>
int main()
{
    int *p[5], i, j, n;
    for(i=0; i<5; i++)
    {
        scanf("%d", &n);
        p[i] = (int *)malloc(sizeof(int)*n);
        printf("p[%d] = %d\n", i,p[i]);
        for(j=0; j<n; j++)
        {
            scanf("%d", *(p+i)+j);
            printf("i = %d, j = %d, add = %d\n",i,j, *(p+i)+j);
        }
        puts("");   
    }
    return 0;
}
