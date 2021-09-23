#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[((x)/64)] & 1 << ((x)%64)/2)
#define cngbit(x) (t[((x)/64)] |= 1 << ((x)%64)/2)
#define last 1100
int t[last/64 + 2];
vector<int>prime;
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
int calc(int a, int b)
{
	int ans=1;
	for(int i=0; prime[i]*prime[i]<=a && prime[i]*prime[i]<=b; i++)
	{
		int c1=0, c2=0;
		while(!(a%prime[i])){
			c1++;
			a/=prime[i];
		}
		while(!(b%prime[i]))
		{
			c2++;
			b/=prime[i];
		}
		ans *= min(c2, c1)+1;
	}
	if(a!=1 && b!=1 && (!(a%b) || !(b%a)))
		ans *= 2;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	sieve();
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		cout << calc(a, b) << "\n";
	}
	return 0;
}