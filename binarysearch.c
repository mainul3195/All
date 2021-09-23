#include <stdio.h>
int main()
{
	int arr[20], s,e,m,i,n,t;
	scanf("%d %d", &n, &t);
	for(i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}
	s=0; e=n-1;

	while(s!=e)
	{
		m=(s+e)/2;
		if(arr[m]<t)
			s=m+1;
		else
			e=m;
	}
	if(arr[s]==t)
	printf("found %d", s+1);
	else
		printf("not found");

	return 0;
}