#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector<long long> v;
	int n,x, pos;
	cin >> n >> x >> pos;
	int less=x-1, greater=n-x;
	for(int l=0, r=n; l<r;)
	{
		int mid=(l+r)/2;
		if(mid==pos)
		{
			v.push_back(1);
			l=mid+1;
		}
		else if(mid<pos)
		{
			v.push_back(less--);
			l=mid+1;
		}
		else if(mid>pos)
		{
			v.push_back(greater--);
			r=mid;
		}
	}
	long long ans=1;
	if(less<0 || greater <0)
		ans=0;
	else
	{
		for(int i=0; i<v.size(); i++)
			ans=(ans*v[i])%MOD;
		for(int i=n-v.size(); i>0; i--)
			ans=(ans*i)%MOD;
	}
	cout << ans << "\n";
	return 0;
}