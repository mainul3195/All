#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		pair<int, int> p;
		vector < pair < int, int> > v;
		cin >> n;
		for(int j,i=1; i<=n; i++)
		{
			cin >> j;
			p=make_pair(j, i);
			v.push_back(p);
		}
		sort(v.begin(), v.end());
		int ans=-1;
		for(int i=0; i<n-1; i++)
			if(v[i].first==v[i+1].first)
			{
				if(ans==-1)
					ans=v[i+1].second-v[i].second+1;
				else if(v[i+1].second-v[i].second < ans)
					ans=v[i+1].second-v[i].second+1;
			}
		cout << ans << "\n";
	}
	return 0;
}