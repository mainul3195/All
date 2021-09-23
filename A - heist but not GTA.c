#include<stdio.h>
char prime[10000005];
int main()
{
	prime[0]=1;prime[1]=1;
	int t,i,j,count,n;

	for(i=3; i<=3162; i+=2)
		if(!prime[i])
			for(j=i*i; j<=10000000; j+=i)
				prime[j]=1;

	scanf("%d", &t);
	for(i=1; i<=t; i++)
	{
		count=0;
		scanf("%d", &n);
		if(n==4)
			count++;
		for(j=3; j<=n/2; j+=2)
			if(!prime[j] && !prime[n-j])
				count++;
		printf("Case %d: %d\n",i, count);
	}
	return 0;
}