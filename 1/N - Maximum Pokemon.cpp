#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[157];
vector<int> prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=100; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=10000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=10000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return ;
}
int ar[100010],maxm;
void kill(int n)
{
	if(n>maxm)
		maxm=n;
	for(int i=0; prime[i]*prime[i]<=n; i++)
	{
		if(!(n%prime[i]))
		{
			ar[prime[i]]++;
			while(!(n%prime[i]))
				n/=prime[i];
		}
	}
	if(n!=1)
		ar[n]++;
	return;
}
int main()
{
	ar[1]++;
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		int j;
		cin >> j;
		kill(j);
	}
	int mx=0;
	for(int i=0; i<=maxm; i++)
		if(ar[i]>mx)
			mx=ar[i];
	cout << mx ;
	return 0;
}