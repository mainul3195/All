#include<stdio.h>
#include<math.h>
int a[10000000],b[3200000],c;
int find_i(int left, int right, int n)
{
	int mid=(left+right)/2;
	if((a[mid]<n && a[mid+1]>n)||mid==0)
		return mid;
	if(n<a[mid])
		return find_i(left, mid-1, n);
	else
		return find_i(mid+1, right, n);

}
int main()
{
	int n,i,j,k,l;
	a[c++]=2;
	b[0] |= 1<<0;
	b[0] |= 1<<1;
	for(i=4; i<=100000000; i+=2)
	{
		k=i/32;
		l=i%32;
		b[k] |= 1<<l;
	}
	for(i=3; i<=10000; i+=2)
	{
		k=i/32;
		l=i%32;
		if(!(b[k] & 1<<l))
			for(j=i*i; j<=100000000; j+=2*i)
			{
				k=j/32;
				l=j%32;
				b[k] |= 1<<l;
			}
	}
	for(i=3; i<=100000000; i++)
	{
		k=i/32;
		l=i%32;
		if(!(b[k] & 1<<l))
			a[c++]=i;
	}
	while(~scanf("%d", &n))
	{
		int flag = 1;
		if(n%2)
		{
			if(n==1) printf("%d is not the sum of two primes!\n",1);
			else
			{
				k=(n-2)/32;
				l=(n-2)%32;
				if(!(b[k] & 1<<l))
					printf("%d is the sum of %d and %d.\n",n, 2, n-2);
				else
					printf("%d is not the sum of two primes!\n",n);
			}
			
		}
		else
		{
			i=find_i(0,c-1,n/2)+1;
			while(--i>-1)
			{
				k=(n-a[i])/32;
				l=(n-a[i])%32;
				if(!(b[k] & 1<<l) && a[i]!=n-a[i])
				{
					printf("%d is the sum of %d and %d.\n", n, a[i], n-a[i]);
					flag=0;
					break;
				}
			}
			if(flag)
				printf("%d is not the sum of two primes!\n", n);
		}
	}
	
	return 0;	
}