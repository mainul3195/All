#include<stdio.h>
int a[100000000];
int main()
{
	int i,j,k,l,count=1;;
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
	printf("2\n");
	for(i=3; i<=100000000; i+=2)
	{
		k=i/32;
		l=i%32;
		if(!(a[k] & 1<<l))
		{
			count++;
			if(count%100==1)
				printf("%d\n", i);
		}
	}
}