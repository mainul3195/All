#include<bits/stdc++.h>
using namespace std;
#define last 100000000
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[last/64 + 2];
vector<int> prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i*i<=last; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=last; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=last; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	sieve();
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << prime[n-1] << "\n";
	}
	return 0;
}