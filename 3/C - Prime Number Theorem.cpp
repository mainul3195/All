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
int find(int n)
{
	int l=0, r=5761454, mid,ans;
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
	int n;
	while(cin >> n and n)
	{
		int a=find(n);
		cout << fixed <<  setprecision(1) << (fabs(a+1-n/log(n))/(a+1))*100 << "\n";
	}
	return 0;
}