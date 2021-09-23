#include<stdio.h>
int a[32000000];
void execute()
{
	int n,m,i,k,l;
	scanf("%d %d", &m,&n)	;
	if(2>=m && 2<=n) printf("2\n");
	if(!(m%2)) m++;
	for(i=m; i<=n; i+=2)
	{
		k=i/32;
		l=i%32;
		if(!(a[k] & 1<<l))
			printf("%d\n", i);
	}
}

int main()
{
	int i,j,k,l;
	for(i=3; i<=31622; i+=2)
	{
		k=i/32;
		l=i%32;
		if(!(a[k] & 1<<l))
		{
			for(j=i*i; j<=1000000000; j+=2*i)
			{
				k=j/32;
				l=j%32;
				a[k] |= 1<<l;
			}
		}
	}
	a[0] |= 1<<1;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		execute();
		puts("");
	}
	return 0;
}