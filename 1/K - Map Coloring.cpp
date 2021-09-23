#include<bits/stdc++.h>
using namespace std;
vector<int> node[300],vis(300);
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
	cin >> n;
	for(int i=0; i<=n; i++)
		node[i].clear();
	fill(vis.begin(), vis.end(), 0);
	for(int i=1; i<=n; i++)
	{
		int l;
		while(cin >> l and l)
		{
			node[i].push_back(l);
			node[l].push_back(i);
		}
	}
	bool ok=1;
	for(int i=0; i<n; i++)
		if(!vis[i])
			ok &= bfs(i);
	if(!ok)
		cout << "-1\n";
	else
	{
		for(int i=1; i<=n; i++)
			cout << vis[i]%2;
		cout << "\n";
	}
	return 0;
}