#include<stdio.h>
#define sz 100100
int arr[sz],flag;

void sort(int a[], int n)
{
    int i, j, temp;
    for (i=1; i<n; i++)
    {
        flag = 1;
        for (j=1; j<n; j++)
            if(a[j-1] > a[j])
            {
                flag = 0;
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] =  temp;
            }
        if(flag)
            break;
    }
}

int comp(const void *a, const void *b)
{
    return ( *(int*)b - *(int *)a);
}

int main()
{
    int n, i;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%d", &arr[i]);

//    sort(arr,n);
    qsort(arr,n,sizeof(int),comp);
    for (i=0; i<n; i++)
        printf("%d%c",arr[i],",\n"[i==n-1]);

    return 0;
}
/**
13
4
6
-9
17
6
8
5
4
3
1
0
8
7
*/
