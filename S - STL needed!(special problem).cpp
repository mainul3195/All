#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s,ans;
	int max=-10000, i,j,k;
	map < string , int > mp,mp2;
	pair < string, int> p;
	vector<pair<string, int> > v;
	for(i=0; i<n; i++)
	{
		cin >> s >> j;
		if(mp.count(s))
			mp[s]+=j;
		else
			mp[s]=j;
		p=make_pair(s, j);
		v.push_back(p);
	}
	for(auto it=mp.begin(); it!=mp.end(); it++)
	{
		//cout << it->first << " = " << it->second << "\n";
		if(it->second > max)
			max=it->second;
	}
	for(i=0; i<n; i++)
	{
		if(mp2.count(v[i].first))
			mp2[v[i].first]+=v[i].second;
		else
			mp2[v[i].first]=v[i].second;
		if(mp2[v[i].first]>=max && mp[v[i].first]==max)
		{
			ans=v[i].first;
			break;
		}
	}
	cout << ans;
	return 0;
}