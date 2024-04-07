#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second<b.second;
}
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int> > v;
	for(int i=1; i<=n; i++)
	{
		int j;
		cin >> j ;
		v.push_back({j,i});
	}
	sort(v.begin(), v.end());
	for(int i=1; i<v.size(); i++)
		if(v[i].first==v[i-1].first)
			v[i-1].first=0, v[i-1].second=0;
	sort(v.begin(), v.end(), cmp);
	int count=0;
	for(int i=0; i<v.size(); i++)
		if(v[i].second)
			count++;
	cout << count << "\n";
	for(int i=0; i<v.size(); i++)
		if(v[i].second)
			cout << v[i].first << " \n"[i==v.size()-1];
	return 0;
}
