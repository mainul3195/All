#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s;
	map<string, int> mp;
	int j=n;
	while(j--)
	{
		cin >> s;
		mp[s]++;
	}
	vector<pair<int, string> > p;
	for(auto i: mp)
		p.push_back({i.second, i.first});
	sort(p.begin(), p.end(), cmp);
	int mx=p[0].first;
	int i=0;
	while(i<n && p[i].first==mx)
		cout << p[i++].second << "\n";
	return 0;
}