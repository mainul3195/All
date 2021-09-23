#include<bits/stdc++.h>
using namespace std;
bool cmp(pair <int, int> p1, pair < int, int> p2)
{
	return p1.first < p2.first;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k,p ,i,t;
	pair < int , int> q;
	vector< pair < int, int > > v;
	cin >> n >> k >> p;
	int vb[n+1]={0};
	for(i=1; i<=n; i++)
	{
		cin >> t;
		q=make_pair(t, i);
		v.push_back(q);
	}
	sort ( v.begin(), v.end(), cmp);
	int j=1;
	vb[v[0].second]=++j;
	for(i=1; i<n; i++)
	{
		if(v[i].first-v[i-1].first <= k)
			vb[v[i].second]=j;
		else
			vb[v[i].second]=++j;
	}
	int l, r;
	for(i=0; i<p; i++)
		{
			cin >> l >> r;
			if(vb[l]==vb[r])
				cout << "Yes\n";
			else cout << "No\n";
		}
	return 0;
}