#include<bits/stdc++.h>
using namespace std;
void execute();
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		execute();
	return 0;
}
void execute()
{
	int n,b, i, g, flag=0;
	scanf("%d %d ", &n, &g);
	for(i=1; i<n; i++)
	{
		scanf("%d", &b);
		if(flag) continue;
		g= __gcd(g,b);
		if(g==1)
		{
			printf("%d\n", n);
			flag=1;
		}
	}
	if(!flag)
		printf("-1\n");
	return;
}