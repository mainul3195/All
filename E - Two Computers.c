#include<stdio.h>
int main()
{
	int t,n;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		if(n==20) printf("10 10\n");
		else
		printf("%d %d\n", n%10, n-n%10);
	}
	return 0;
}