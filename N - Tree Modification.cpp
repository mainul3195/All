#include<bits/stdc++.h>
using namespace std;
#define sz 200005
vector<int> node[sz],vis(sz);
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
	int j,k;
	for(int i=1; i<n; i++)
	{
		cin >> j >> k;
		node[j].push_back(k);
		node[k].push_back(j);
	}
	bfs(1);
	int white=0;
	for(int i=1; i<=n; i++)
		if(vis[i]%2)
			white++;
	cout << min(white, n-white)-1 << "\n";
	return 0;
}