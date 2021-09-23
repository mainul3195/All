#include<stdio.h>
#include<math.h>

int a[32000],prime[100000];
void execute(int);
int main()
{
	int i,j,k,l,t;
	for(i=3; i<=1009; i+=2)
	{
		k=i/32;
		l=i%32;
		if(!(a[k] & 1<<l))
			for(j=i*i; j<=1020000; j+=2*i)
			{
				k=j/32;
				l=j%32;
				a[k] |= 1<<l;
			}
	}
	int count=0;
	prime[count++]=2;
	for(i=3; i<=1020000; i+=2)
	{
		k=i/32;
		l=i%32;
		if(!(a[k] & 1<<l))
			prime[count++]=i;
	}

	scanf("%d", &t);
	i=0;
	while(t--)
		execute(++i);
	return 0;
}

void execute(int a)
{
	long long lim,n,mul=1;
	int pd[200]={0},i,j=-1;
	scanf("%lld", &n);
	lim=sqrt(n);
	for(i=0; prime[i]<=lim && n>1; i++)
	{
		if(!(n%prime[i]))
		{
			j++;
			while(!(n%prime[i]) && n>1)
			{
				n/=prime[i];
				pd[j]++;
			}
		}
	}
	if(n!=1)pd[++j]++;
	for(i=0; pd[i]; i++)
		mul*=(pd[i]+1);
	mul--;
	printf("Case %d: %lld\n", a, mul);
	return;
}