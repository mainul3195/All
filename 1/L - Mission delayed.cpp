#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005], starting,nodedis(1001);
void bfs(int n)
{
	queue<int>q;
	vector<int>lebel(10005,0), vis(10005,0);
	lebel[n]=0;
	vis[n]=1;
	q.push(n);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int j : v[u])
		{
			if(vis[j])
				continue;
			vis[j]=1;
			lebel[j]=lebel[u]+1;
			nodedis[j]+=lebel[j];
			q.push(j);
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	int tc=0;
	cin >> t;
	while(t--)
	{
		fill(nodedis.begin(), nodedis.end(), 0);
		for(int i=0; i<=1000; i++)
			v[i].clear();
		int n,r;
		cin >> n >> r;
		for(int i=0; i<r; i++)
		{
			int j,k;
			cin >> j >> k;
			v[j].push_back(k);
			v[k].push_back(j);
		}
		int s, e;
		cin >> s >> e;
		bfs(s);
		bfs(e);
		int mx=0;
		for(int i=0; i<n; i++)
			mx=max(mx,nodedis[i]);
		cout << "Case " << ++tc << ": " << mx << "\n";
	}
	return 0;
}