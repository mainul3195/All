#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,n,x,lim;
	int count=0;
	scanf("%d %d", &n, &x);
	lim=sqrt(x);
	for(a=1; a<=lim; a++)
	{
		b=x/a;
		if(b<=n && a*b==x)
		{
			//printf("%d %d\n", a , b);
			count+=2;
		}
	}
	if(b*b==x && b<=n)
		count--;
	printf("%d", count);	
	return 0;
}
