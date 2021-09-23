#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,i,j;
	long long sum=0,ans=0;
	vector<int>v;
	cin >> n >> m;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	i=-1, j=0;
	while(i<n)
	{
		if(sum<=m)
		{
			ans=max(ans,sum);
			if(++i<n)
				sum+=v[i];
		}
		else
			sum-=v[j++];
	}
	cout << ans;
	return 0;
}