#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ckbit(x) (t[x/64] & 1 << (x%64)/2)
#define cngbit(x) (t[x/64] |= 1 << (x%64)/2)
int t[2000];
vector<long long> prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=357; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=127449; j+=2*i)
				cngbit(j);
	for(int i=3; i<=127449; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
//(a^b)%m
long long power(long long a, long long b, long long m)
{
	if(b==1)
		return a%m;
	long long temp=power(a, b/2, m);
	temp=(temp*temp)%m;
	if(b&1)
		temp= temp*a % m;
	return temp;
}
long long invrse( int a, int b, long long &x, long long &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	long long x1, y1;
	int g=invrse(b, a%b, x1, y1);
	x=y1;
	y=x1- (a/b)*y1;
	return (x+MOD) %MOD;
}
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	long long inv[100000];
	inv[1]=1;
	for(int i=2; i<100000; i++)
		inv[i]=(MOD-MOD/i*inv[MOD%i]) % MOD;
//	cout << power(5, 10, 11);
	int t, tc=0;
	cin >> t;
	while(t--)
	{
		long long ans=1;
		long long n,m;
		cin >> n >> m;
		for(int i=0; prime[i]*(long long)prime[i]<=n; i++)
		{
		 	int c=0,sum=0;
		 	while(!(n%prime[i]))
		 	{
		 		n/=prime[i];
		 		c++;
		 	}
			if(c)
			{
				sum=(((power(prime[i], m*c+1, MOD)-1+MOD)%MOD)*power(prime[i]-1, MOD-2, MOD))%MOD;
				ans= (ans*sum)%MOD;
			}
		}
		if(n!=1)
		{
			long long x,y,sum=0;
			//cout << power(n-1, MOD-2, MOD)%MOD << "\n";
			sum=(((power(n, m+1, MOD)-1+MOD)%MOD)*power(n-1, MOD-2, MOD))%MOD;
			ans = (ans*sum)%MOD;	
		}
		cout << "Case " << ++tc << ": " << ans << "\n";
	}
	return 0;
}