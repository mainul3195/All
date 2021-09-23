#include<bits/stdc++.h>
using namespace std;
vector<int> node[2003],vis(2003);
int n;
bool bfs(int s)
{
	vis[s]=2;
	queue<int> q;
	q.push(s);
	bool ok=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i: node[u])
		{
			if(vis[i] && vis[i]%2==vis[u]%2)
				ok=0;
			if(vis[i])
				continue;
			vis[i]=vis[u]+1;
			q.push(i);
		}
	}
	return ok;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int tc=0;
	while(t--)
	{
		int l;
		cin >> n >> l;
		for(int i=0; i<=n; i++)
			node[i].clear();
		fill(vis.begin(), vis.end(), 0);
		int j,k;
		while(l--)
		{
			cin >> j >> k;
			node[j].push_back(k);
			node[k].push_back(j);
		}
		bool ok=1;
		for(int i=0; i<n; i++)
			if(!vis[i])
				ok &= bfs(i);
		cout << "Scenario #" << ++tc << ":\n";
		if(!ok)
			cout << "Suspicious bugs found!\n";
		else
			cout << "No suspicious bugs found!\n";
	}
	return 0;
}