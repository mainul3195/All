#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[25];
vector<int> prime;
long long sum;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=38; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1427; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=1427; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	//cout << prime[prime.size()-1];
	return;
}
void execute(int n)
{
	for(int i=0; prime[i]*prime[i]<=n; i++)
		while(!(n%prime[i]))
		{
			sum+=prime[i];
			n/=prime[i];
		}
	if(n!=1)
		sum+=n;
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int n;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		execute(n);
	}
	cout << sum;
	return 0;
}