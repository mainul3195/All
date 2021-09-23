#include<stdio.h>


void test(void)
{
	int n,k,a[40], b[40],i,j,sum,tmp,flag;
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++)
		scanf("%d", a+i);
	for(i=0; i<n; i++)
		scanf("%d", b+i);
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
			if(b[j]<b[j+1])
			{
				tmp = b[j];
				b[j] = b[j+1];
				b[j+1] = tmp;
			}
		}
	}
	for(i=0; i<k; i++)
	{
		flag = 1;
		if(a[i]<b[i])
		{
			flag = 0;
			tmp = a[i];
			a[i] = b[i];
			b[i] = tmp;
		}
		if(flag)
			break;
	}
	sum = 0;
	for(i=0; i<n; i++)
	{
		sum+=a[i];
	}
	printf("%d\n", sum);
	return;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}