#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, x, y;
		cin >> n >> k >> x >> y;
		if(x==y)
		{
			cout << n << " " << n << "\n";
			continue;
		}
		vector<pair<int, int>> v;
		if(x<y)
		{
			v.push_back({0, y-x});
			v.push_back({n-y+x, n});
			v.push_back({n, n-y+x});
			v.push_back({y-x, 0});
		}
		else
		{
			v.push_back({x-y, 0});
			v.push_back({n, n-x+y});
			v.push_back({n-x+y, n});
			v.push_back({0, x-y});
		}
		cout << v[k%4].first << " " << v[k%4].second << "\n";
	}
	return 0;
}