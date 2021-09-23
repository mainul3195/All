#include<bits/stdc++.h>
using namespace std;
#define ckbit(x) (t[(x)/32] & 1 << ((x)%32))
#define cngbit(x) (t[(x)/32] |= 1 << ((x)%32))
int t[40];
vector<int> prime;
void sieve()
{
	prime.push_back(2);
	for(int i=4; i<=1000; i+=2)
		cngbit(i);
	for(int i=3; i<=31; i+=2)
		if(!ckbit(i))
			for(int j=i*i; j<=1000; j+=2*i)
				if(!ckbit(j))
					cngbit(j);
	for(int i=3; i<=1000; i+=2)
		if(!ckbit(i))
			prime.push_back(i);
	return;
}
bool success(int n)
{
	if(n==1)
		return 0;
	int ans=1;
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
	if(ckbit(ans))
		return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	sieve();
	cin >> t;
	while(t--)
	{
		int l,r;
		vector<int> ans;
		cin >> l >> r;
		for(int i=l; i<=r; i++)
			if(success(i))
				ans.push_back(i);
		if(!ans.size())
			cout << "-1\n";
		else
			for(int i=0; i<ans.size(); i++)
				cout << ans[i] << " \n"[i==ans.size()-1];
	}
	return 0;
}