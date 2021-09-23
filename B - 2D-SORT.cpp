#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first==b.first)
		return a.second>b.second;
	return a.first<b.first;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	vector< pair<int, int > > v;
	pair<int, int> p;
	int t;
	cin >> t;
	while(t--)
	{
		int n ;
		cin >> n;
		for(int i=0; i<n; i++)
		{
			int j, k;
			cin >> j >> k;
			p={j,k};
			v.push_back(p);
		}
		sort(v.begin(), v.end(), cmp);
		for(int i=0; i<n; i++)
			cout << v[i].first << " " << v[i].second << "\n";
		v.clear();
	}
	return 0;
}