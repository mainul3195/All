#include<bits/stdc++.h>
using namespace std;
vector<int> node[10004], indeg(10004), ans;
set<int> s;
bool topsort(int n)
{
	for(int i=1; i<=n; i++)
		if(indeg[i]==0)
			s.insert(i);
	while(!s.empty())
	{
		int t= *s.begin();
		s.erase(s.begin());
		ans.push_back(t);
		for(int i=0; i<node[t].size(); i++)
		{
			indeg[node[t][i]]--;
			if(!indeg[node[t][i]])
				s.insert(node[t][i]);
		}
	}
	for(int i=1; i<=n; i++)
		if(indeg[i])
			return 0;
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int u,v; 
		cin >>  u >> v;
		node[u].push_back(v);
		indeg[v]++;
	}
	if(!topsort(n))
		cout << "Sandro fails.\n";
	else
		for(int i=0; i<ans.size(); i++)
			cout << ans[i] << " \n"[i==ans.size()-1];
	return 0;
}