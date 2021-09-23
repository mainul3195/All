#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(x) (t[(x)/64] |= 1 << ((x)%64)/2)
int t[20];
vector<int>prime;
void sieve()
{
	prime.push_back(2);
	for(int i=3; i<=33; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1100; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=1100; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
int head(int a, int b)
{
	int ans=1;
	for(int i=0; prime[i]*prime[i]<=a && prime[i]*prime[i]<=b; i++)
	{
		int count=0;
		int temp1=0,temp2=0;
		while(!(b%prime[i]))
		{
			temp1++;
			b/=prime[i];
		}
		while(!(a%prime[i]))
		{
			temp2++;
			a/=prime[i];
		}
		count=min(temp2, temp1);
		if(count)
			ans*=(count+1);
	}
	if(a!=1 &&  b!=1 && (!(a%b) || !(b%a) || a==b))
		ans*=2;
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
		int a,b;
		cin >> a >> b;
		cout << head(a,b) << "\n";
	}
	return 0;
}