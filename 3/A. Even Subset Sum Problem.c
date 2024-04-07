#include<stdio.h>
int main()
{
	int t, n, i, arr[101];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%d", arr+i);
		for(i=0; i<n; i++)
			if(arr[i]%2==0)
				break;
		if(i==n)
		{
			if(n>1)
				printf("2\n1 2\n");
			else
				printf("-1\n");
		}
		else
			printf("1\n%d\n", i+1);

	}

	return 0;
}