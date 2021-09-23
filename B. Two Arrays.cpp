#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		vector<int>ans(n,0);
		vector<pair < int, int > > v;
		pair<int, int>p;
		for(int i=0; i<n; i++)
		{
			int j;
			cin >> j;
			p={j, i};
			v.push_back(p);
		}
		sort(v.begin(), v.end());
		bool flag=1;
		int lastind;
		for(int i=0, j=n-1; i<j;)
		{
			if(v[i].first+v[j].first==k)
			{
				ans[v[j].second]=1;
				i++,j--;
			}
			else if(v[i].first+v[j].first<k)
				i++;
			else
				j--;
		}
		for(int i=0; i<n ;i++)
			cout << ans[i] << " \n"[i==n-1];
	}
	return 0;
}