#include<stdio.h>
int arr[200001];
int main()
{
	long long t,i,n;
	scanf("%lld", &t);
	while(t--)
	{
		scanf("%lld", &n);

		for(i=0; i<n; i++)
			scanf("%lld", &arr[i]);
		long long max,sum=0,tmp;
		
		for(i=0; i<n;)
		{
			if(arr[i]<0)
			{
				max=arr[i];
				for(i++; arr[i]<0 && i<n; i++)
					if(arr[i]>max)
						max = arr[i];
			}
			else
			{
				max=arr[i];
				for(i++; arr[i]>0 && i<n; i++)
					if(arr[i]>max)
						max = arr[i];
			}
			sum += max;
		}
		printf("%lld\n", sum);
		for(i=0; i<n; i++)
			arr[i]=0;
	}
}