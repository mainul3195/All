#include<bits/stdc++.h>
using namespace std;
#define ckbit(y,x) (y[(x)/64] & 1 << ((x)%64)/2)
#define cngbit(y,x) (y[(x)/64] |= 1 << ((x)%64)/2)
int t[400000];
vector<int>prime;
void sieve()
{
	for(int i=3; i<=3163; i+=2)
		if(!ckbit(t,i))
			for(int j=i*i; j<=10000000; j+=2*i)
				if(!ckbit(t,j))
					cngbit(t,j);
	prime.push_back(2);
	for(int i=3; i<=10000000; i+=2)
		if(!ckbit(t,i))
			prime.push_back(i);
	// for(int i=0; i<=25; i++)
	// 	cout << prime[i] << "\n";
	return;
}
int getpos1(int n)
{
	int l=0, r=prime.size()-1, mid, ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(prime[mid]>=n)
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return ans;
}
int getpos2(int n)
{
	int l=0, r=prime.size()-1, mid, ans;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(prime[mid]<=n)
		{
			ans=mid;
			l=mid+1;
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
	while(cin >> n)
	{
		if(!n)
			return 0;
		int a=getpos1(n);
		int b=getpos2(n);
	//	cout << a << " " << b << "\n";
		cout << prime[a]-prime[b] << "\n";
	}
}