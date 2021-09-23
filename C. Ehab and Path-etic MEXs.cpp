#include<bits/stdc++.h>
using namespace std;
vector<int> node[100005],child(100005,0);
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> storage;
	for(int i=0; i<n-1; i++)
	{
		int j,k;
		cin >> j >>k;
		storage.push_back({j,k});
		node[j].push_back(k);
		node[k].push_back(j);
	}
	map<pair<int, int>, int> mp;
	int j=1;
	for(int i=1; i<=n; i++)
	{
		if(node[i].size()==1)
		{
			if(mp[{i, node[i][0]}] || mp[{node[i][0], i}])
				continue;
			mp[{i, node[i][0]}] = mp[{node[i][0], i}] = j++;
		}
	}
	for(int i=0; i<storage.size(); i++)
		if(!mp[{storage[i].first, storage[i].second}])
			mp[{storage[i].first, storage[i].second}] = mp[{storage[i].second, storage[i].first}] = j++;
	for(auto i: storage)
		cout << mp[{i.first, i.second}]-1 << "\n";
	return 0;
}