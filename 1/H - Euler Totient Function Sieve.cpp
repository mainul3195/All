#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1<< (((x)%64)/2))
#define cngbit(x) (t[(x)/64] |= 1<< (((x)%64)/2))

int t[200000];
vector<long long>prime;
void sieve()
{
	for(int i=3; i<=3163; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=10000100; j+=2*i)
				cngbit(j);
	prime.push_back(2);
	for(int i=3; i<=10000100; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
long long phi(long long n)
{
	long long ans=n;
	for(int i=0; (long long)prime[i]*prime[i] <=n; i++)
	{
		if(!(n%prime[i]))
		{
			while(!(n%prime[i]))
				n/=prime[i];
			ans = (long long)ans*(prime[i]-1)/prime[i];
		}
	}
	if(n!=1)
		ans = (long long)ans*(n-1)/n;
	return ans;
}
#define lim 1000005
int totient[lim+1];
long long sum[lim+1];
void phi()
{
	for(int i=1; i<=10004; i++)
		totient[i]=i;
	for(int i=0; prime[i]<=10003; i++)
	{
		totient[prime[i]]--;
		for(int j=prime[i]*2; j<=10003; j+=prime[i])
			totient[j]=(long long)totient[j]*(prime[i]-1)/prime[i];
	}
	for(int i=1; i<=10003; i++)
		sum[i]=totient[i]+sum[i-1];
	return;
}
int main()
{
	sieve();
	long long a, b;
	cin >> a >> b;
	for(long long i=a; i<=b; i++)
		cout << phi(i) << "\n";
	return 0;
}