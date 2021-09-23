#include<stdio.h>
int main()
{
	int n,a,b,i,p,q,r,s,t, sum, temp, num;
	while(~scanf("%d %d %d", &n, &a, &b))
	{
		p=q=r=s=t=sum=0;
		for(i=1; i<=n; i++)
		{
			temp=0;
			for(num=i; num!=0; num/=10)
				temp+=num%10;
			if(temp>=a && temp<=b)
				sum+=i;
		}
		printf("%d\n", sum);
	}
	return 0;
}