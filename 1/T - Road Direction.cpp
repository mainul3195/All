#include<bits/stdc++.h>
using namespace std;
vector<pair< int, int> > nodes;
vector<int>edge[200005], vis, order, position;
void dfs(int n)
{
	vis[n]=1;
	for(int i: edge[n])
		if(!vis[i])
			dfs(i);
	order.push_back(n);
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=0; i<=n; i++)
			edge[i].clear();
		nodes.clear();
		for(int i=0; i<m; i++)
		{
			int u,v,x;
			cin >> x >> u >> v;
			if(x)
				edge[u].push_back(v);
			nodes.push_back({u,v});
		}
		order.clear();
		vis= vector<int> (n+1);
		for(int i=1; i<=n; i++)
			if(!vis[i])
				dfs(i);
		reverse(order.begin(), order.end());
		position = vector<int> (n+1);
		for(int i=0; i<order.size(); i++)
			position[order[i]]=i;
		bool ok=1;
		for(int i=1; i<=n; i++)
			for(int j: edge[i])
				if(position[j] < position[i])
					ok=0;
		if(!ok)
			cout << "NO\n";
		else
		{
			cout << "YES\n";
			for(auto e : nodes)
			{
				if(position[e.first]<position[e.second])
					cout << e.first << " " << e.second << "\n";
				else
					cout << e.second << " " << e.first << "\n";
			}
		}
	}
	return 0;
}