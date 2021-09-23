#include<bits/stdc++.h>
using namespace std;
vector<int> node[200005], vis(200005);
int bfs(int s)
{
	int count=0;
	vis[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u=q.fornt();
		count++;
		q.pop();
		for(auto i: node[u])
			if(!vis[i])
			{
				vis[i]=1;
				q.push(i);
			}
	}
	return count;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,a,b;
		cin >> n >> m >> a >> b;
		for(int i=0; i<=n; i++)
			node[i].clear();
		vis.clear();
		int j,k;
		for(int i=0; i<m; i++)
		{
			cin >> j >> k;
			node[j].push_back(k);
			node[k].push_back(j);
		}
		vis[a]=vis[b]=1;
		int tot_vis=2;
		long long ans=0;
		for(int i=1; i<=n; i++)
		{
			if(!vis[i])
			{
				int temp=bfs(i);
				tot_vis+=temp;
				if(tot_vis!=n && !ans)
					ans=1;
				ans*=temp;
				if(tot_vis==n)
					break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}