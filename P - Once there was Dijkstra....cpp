#include<bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > node[100005];
vector<long long> dis(100005) , vis(100005);
vector<int> parent(100005);
int nd;
long long dijkstra(long long start, long long end)
{
	pair<long long, long long> front;
	fill(dis.begin(), dis.end(), 999999999999);
	parent[1]=-1;
	dis[1]=0;
	vis[start]=1;
	priority_queue< pair<long long, long long>, vector<pair<long long, long long> > , greater<pair<long long, long long> > > q;
	q.push({0,start});
	while(!q.empty())
	{
		front = q.top();
		q.pop();
		nd=front.second;

		if(nd==end)
			return dis[nd];
		for(int i=0; i<node[nd].size(); i++)
		{
			int temp=node[nd][i].first;
			long long weight= node[nd][i].second;

			if(dis[temp] > dis[nd] + weight)
			{
				dis[temp] = dis[nd] + weight;
				parent[temp]= nd;
				q.push({dis[temp], temp});
			}
		}
	}
	return -1;
}
vector<int> path;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0; i<m; i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		node[u].push_back({v, w});
		node[v].push_back({u, w});
	}
	long long l=dijkstra(1, n);
	//cout << path.size();
	if(l==-1)
		cout << "-1\n" ;
	else
	{
		int last=n;
		while(last != -1)
		{
			path.push_back(last);
			last=parent[last];
		}
		reverse(path.begin(), path.end());
		for(int i=0; i<path.size(); i++)
			cout << path[i] << " \n"[i==path.size()-1];
	}
	return 0;
}