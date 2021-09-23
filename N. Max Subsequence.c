#include<stdio.h>
int main()
{
	char a,d;
	int c=1,i=0,n;
	scanf("%d ", &n);n--;
	scanf("%c", &a);
	while(n--)
		{
			scanf("%c", &d);
			if(a!=d) c++;
			a=d;
		}
	printf("%d", c);
	return 0;
}