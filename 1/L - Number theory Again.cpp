#include<bits/stdc++.h>
using namespace std;
int prime[31300];
void seive();
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,p,q;
	seive();
	long long a, b;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a;
		b=sqrt(a);
		p=b/32;
		q=b%32;
		if(b*b==a && !(prime[p] & 1<<q))
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
	return 0;
}
void seive()
{
	int i,j,p,q;
	prime[0] |= 1<<1;
	for(i=4; i<=1000000; i+=2)
	{
		p=i/32;
		q=i%32;
		prime[p] |= 1<<q;
	}
	for(i=3; i<=31250; i+=2)
	{
		p=i/32;
		q=i%32;
		if(!(prime[p] & 1<<q))
			for(j=i*i; j<=1000000; j+=2*i)
			{
				p=j/32;
				q=j%32;
				prime[p] |= 1<< q;
			}		
	}
	return;
}