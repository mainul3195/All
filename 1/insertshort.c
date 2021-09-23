#include<stdio.h>
int main()
{
	int arr[20],i,j,m,n,k;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
    for(i=1; i<n; i++)
	{
		for(j=i;j>0&&arr[j-1]>arr[j]; j--)
		{
			m=arr[j-1];
			arr[j-1]=arr[j];
			arr[j]=m;
		}

	}
	for(i=0; i<n; i++)
		printf("%d%c", arr[i], " \n"[i==n-1]);

    return 0;
}
