#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[500000];
vector<long long>prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=5624; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=31630000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=31630000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
}
void execute(long long n)
{
	vector<pair<long long, int> > pf;
	pair<long long, int>p;
	for(int i=0; prime[i]*prime[i]<=n; i++)
	{
		int count=0;
		while(!(n%prime[i]))
		{
			count++;
			n/=prime[i];
		}
		if(count)
		{
			p={prime[i],count};
			pf.push_back(p);
		}
	}
	if(n!=1)
	{
		p={n,1};
		pf.push_back(p);
	}
	for(int i=0; i<pf.size(); i++)
		cout << pf[i].first << "^" << pf[i].second << " \n"[i==pf.size()-1];
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	long long n;
	while(cin >> n)
	{
		if(!n)
			return 0;
		execute(n);
	}
}