#include<bits/stdc++.h>
using namespace std;
unsigned long long phi[5000006];
void prec()
{
	for(int i=0; i<=5000003; i++)
		phi[i]=i;
	for(int i=2; i<=5000003; i++)
		if(phi[i]==i)
		{
			phi[i]=i-1;
			for(int j=i+i; j<=5000003; j+=i)
				phi[j]=(long long)phi[j]*(i-1)/i;
		}
	for(int i=0; i<=5000003; i++)
		phi[i]= phi[i]*phi[i];
	for(int i=1; i<=5000003; i++)
		phi[i]+=phi[i-1];
	return;
}
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	prec();
	int t;
	scanf("%d", &t);
	int tc=0;
	while(t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("Case %d: %llu\n", ++tc, phi[b]-phi[a-1]);
	}
	return 0;
}