#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[15700];
vector<long long>prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=1000; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1000200; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=1000200; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return ;
}
long long execute(long long n)
{
	long long ans=1;
	for(int i=0; prime[i]*prime[i]<=n; i++)
	{
		int count=0;
		while(!(n%prime[i]))
		{
			count++;
			n/=prime[i];
		}
		if(count)
			ans*=(count+1);
	}
	if(n!=1)
		ans*=2;
	return ans-1;
}
int main()
{
//	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int t,i=0;
	cin >> t;
	while(t--)
	{
		long long n;
		cin >> n;
		cout << "Case " << ++i << ": " << execute(n) << "\n";
	}
	return 0;
}