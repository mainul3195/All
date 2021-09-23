#include<stdio.h>
int main()
{
	int a,b,n, c,i;
	scanf("%d %d", &a, &b);
	c= (a*100)/8;
	for(i = c; i<c+11; i++)
	{
		if((i*8)/100==a && i/10==b)
		{
			printf("%d\n", i);
			break;
		}
	}
	if(i==c+11) printf("-1\n");
	return 0;
}