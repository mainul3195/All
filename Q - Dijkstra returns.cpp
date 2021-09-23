#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
vector<int>dis(5003), dis_from_1(5003);
vector<pair<int, int> > g[5003];
void dijkstra(int start)
{
	fill(dis.begin(), dis.end(), 1000000009);
	dis[start]=0;
	priority_queue< pii, vector<pii>, greater<pii> > q;
	pii tmp;
	q.push({0, start});
	while(!q.empty())
	{
		tmp = q.top();
		q.pop();
		for(auto a: g[tmp.second])
		{
			int x= tmp.first + a.second;
			if(x<dis[a.first])
			{
				dis[a.first]=x;
				q.push({x, a.first});
			}
		}
	}
	return;
}
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int tc=0;
	while(t--)
	{
		int n,r;
		cin >> n >> r;
		for(int i=0; i<=n; i++)
			g[i].clear();
		int u,v,w;
		while(r--)
		{
			cin >> u >> v >> w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
		dijkstra(1);
		for(int i=1; i<=n; i++)
			dis_from_1[i]=dis[i];
		dijkstra(n);
		int mn=1000000000;
		for(int i=1; i<=n; i++)
		{
			for(auto a : g[i])
			{
				int temp = dis_from_1[i] + dis[a.first] + a.second;
				if(temp>dis[1])
					mn=min(mn, temp);
			}
		}
		cout << "Case " << ++tc << ": " << mn << "\n";
	}
	return 0;
}