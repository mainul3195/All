#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[15630];
vector<long long> prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=1000; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1000100; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=1000100; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	// for(int i=0; i<25; i++)
	// 	cout << prime[i] << "\n";
	return;
}
long long execute(long long n)
{
	long long ans=1;
	for(int i=0; prime[i]*prime[i]<=n; i++)
	{
		if(!(n%prime[i]))
		{
			ans*=prime[i];
			while(!(n%prime[i]))
				n/=prime[i];
		}
	}
	if(n!=1)
		ans*=n;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	long long n;
	cin >> n;
	cout << execute(n);
	return 0;
}