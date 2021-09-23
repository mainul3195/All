#include<stdio.h>
void execute();
int main()
{
	int t;
	scanf("%d ", &t);
	while(t--)
		execute();
	return 0;
}
void execute()
{
	char c[1000002];
	int a=0,i=0,f=-1;
	long long res=0;
	scanf(" %s", c);
	for(i=0; c[i]; i++)
	{
		if(c[i]=='+') a++;
		else a--;
		if(a==f)
		{
			res+=i+1;
			f--;
		}
	}
	res+=i;
	printf("%lld\n", res);
	return;
}