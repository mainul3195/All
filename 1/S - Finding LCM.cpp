#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[15700];
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
	return;
}
int power(int a, int b)
{
	int ans=1;
	while(b--)
		ans*=a;
	return ans;
}
long long execute(int a, int b, long long l)
{
	long long ans=1;
	for(int i=0; a!=1 || b!=1; i++)
	{
		int c1=0, c2=0, c=0;
		while(!(a%prime[i]))
		{
			c1++;
			a/=prime[i];
		}
		while(!(b%prime[i]))
		{
			c2++;
			b/=prime[i];
		}
		while(!(l%prime[i]))
		{
			c++;
			l/=prime[i];
		}
		if(max(c1,c2)>c)
			return 0;
		if(max(c1, c2)<c)
			ans*=power(prime[i], c);
	}
	// if(l%a || l%b )
	// 	return 0;
	// l/=a;
	// l/=b;
	ans*=l;
	return ans;
}

int main()
{
	sieve();
	int t, i=0;
	cin >> t;
	while(t--)
	{
		cout << "Case " << ++i << ": ";
		int a,b;
		long long l;
		cin >> a >> b >> l;
		long long temp=execute(a,b,l);
		if(temp)
			cout << temp << "\n";
		else
			cout << "impossible\n";
	}
	return 0;
}