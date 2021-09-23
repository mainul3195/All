#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/32] & 1 << (x)%32)
#define cngbit(x) (t[(x)/32] |= 1 << (x)%32)
int t[350000];
vector<int>prime;
void sieve()
{
	cngbit(0);
	cngbit(1);
	for(int i=4; i<=10000000; i+=2)
		cngbit(i);
	for(int i=3; i<=3163; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=10000000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	prime.push_back(2);
	for(int i=3; i<=10000000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
int findprime(int n)
{
	int l=0, r=prime.size()-1, mid,ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(prime[mid]<=n)
		{
			l=mid+1;
			ans=mid;
		}
		else
			r=mid-1;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	sieve();
	int tc;
	cin >> tc;
	int j=0;
	while(tc--)
	{
		int n,count=0;;
		cin >> n;
		int fp=findprime(n);
		for(int i=fp; i>=0 && prime[i]>=n/2; i--)
			if(!ckbit(n-prime[i]))
				count++;
		cout << "Case " << ++j << ": " << count << "\n";
	}
	return 0;
}