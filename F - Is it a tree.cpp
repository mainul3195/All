#include<bits/stdc++.h>
using namespace std;
vector<int>node[10004],vis(10004,0),par(10004,0);

bool bfs()
{
	par[1]=-1;
	queue<int> q;
	q.push(1);
	vis[1]=1;
	while(!q.empty())
	{
		int n=q.front();
		q.pop();
		for(auto i: node[n])
		{
			if(i==par[n])
				continue;
			if(vis[i])
				return 0;
			vis[i]=1;
			par[i]=n;
			q.push(i);
		}
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	while(m--)
	{
		int u,v;
		cin >> u >> v;
		node[v].push_back(u);
		node[u].push_back(v);
	}
	bool ok;
	ok=bfs();
	for(int i=1; i<=n; i++)
		if(!vis[i])
		{
			ok=0;
			break;
		}
	if(ok)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}