#include<bits/stdc++.h>
using namespace std;
vector<int> node[300],vis(300);
int n;
bool bfs(int s)
{
	vis[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i: node[u])
		{
			if(vis[i] && vis[i]%2==vis[u]%2)
				return 0;
			if(vis[i])
				continue;
			vis[i]=vis[u]+1;
			q.push(i);
		}
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> n and n)
	{
		for(int i=0; i<=n; i++)
			node[i].clear();
		fill(vis.begin(), vis.end(), 0);
		int l;
		cin >> l;
		while(l--)
		{
			int j,k;
			cin >> j >> k;
			node[j].push_back(k);
			node[k].push_back(j);
		}
		bool ok=1;
		for(int i=0; i<n; i++)
			if(!vis[i])
				ok &= bfs(i);
		if(ok)
			cout << "BICOLORABLE.\n";
		else
			cout << "NOT BICOLORABLE.\n";
	}
	return 0;
}