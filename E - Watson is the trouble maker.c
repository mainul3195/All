#include<stdio.h>
#include<math.h>
char sieve[100002];
int main()
{
	int i,n,j,k,l;
	scanf("%d", &n);
	l=sqrt((n+2));
	for(i=4; i<=n+2; i+=2)
		sieve[i]=1;
	for(i=3; i<=l; i+=2)
		if(!(sieve[i]))
			for(j=i*i; j<=n+2; j+=2*i)
				sieve[j]=1;
	if(n<3)printf("1\n");
	else printf("2\n");
	for(i=2; i<=n+1; i++)
	{
		if(sieve[i]) printf("2");
		else printf("1");
		printf("%c", " \n"[i==n+1]);
	}
	return 0;
}