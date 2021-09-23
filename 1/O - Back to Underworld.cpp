#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define sz 20004
vector<int> node[sz],vis(sz);
int n;
int bfs(int s)
{
	vis[s]=2;
	queue<int> q;
	q.push(s);
	int tot=0;
	int white=0;
	while(!q.empty())
	{
		tot++;
		int u=q.front();
		if(vis[u]%2)
			white++;
		q.pop();
		for(int i: node[u])
		{
			if(vis[i])
				continue;
			vis[i]=vis[u]+1;
			q.push(i);
		}
	}
	return max(white, tot-white);
}
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	scanf("%d", &t);
	int tc=0;
	while(t--)
	{
		scanf("%d", &n);
		for(int i=0; i<sz; i++)
			node[i].clear();
		fill(vis.begin(), vis.end(), 0);
		for(int i=0; i<n; i++)
		{
			int j,k;
			scanf("%d %d", &j, &k);
			node[j].push_back(k);
			node[k].push_back(j);
		}
		long long ans=0;
		for(int i=1; i<=20000; i++)
			if(!vis[i] && node[i].size())
				ans += bfs(i);
		//cout << "Case " << ++tc << ": " << ans << "\n";
		printf("Case %d: %lld\n", ++tc, ans);
	}
	return 0;
}