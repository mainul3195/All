#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[800];
vector<long long>prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=227; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=51200; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=51200; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	//cout << prime[prime.size()-1] << "\n";
	return;
}
vector<int>pf;
void find_factor(int n)
{
	if(n<0)
	{
		pf.push_back(-1);
		n*=-1;
	}

	//cout << n << "\n";
	for(int i=0; prime[i]*prime[i]<=n; i++)
	{
		while(!(n%prime[i]))
		{
			pf.push_back(prime[i]);
			n/=prime[i];
		}
	}
	if(n!=1)
		pf.push_back(n);
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	sieve();
	while(cin >> n)
	{
		if(!n)
			return 0;
		find_factor(n);
		//cout << pf.size() << "\n";
		cout << n << " = ";
		for(int i=0; i<pf.size(); i++)
		{
			cout << pf[i];
			if(i==pf.size()-1)
				cout << "\n";
			else
				cout << " x ";
		}
		pf.clear();
	}
}