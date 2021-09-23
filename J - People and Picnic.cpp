#include<bits/stdc++.h>
using namespace std;
vector<int> path[1005],visited,final[1005];
void bfs(int n)
{
	visited.assign(1005,0);
	queue<int> q;
	q.push(n);
	visited[n]=1;
	final[n].push_back(n);
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		for(int i:path[cur])
		{
			if(!visited[i])
			{
				visited[i]=1;
				final[i].push_back(n);
				q.push(i);
			}
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
		int k,n,m;
		cin >> k >> n >> m;
		vector<int>source(k);


		for(int i=0; i<k; i++)
			cin >> source[i];

		for(int i=0; i<1005; i++)
			final[i].clear();
		for(int i=0; i<1005; i++)
			path[i].clear();


		for(int i=0; i<m; i++)
		{
			int j,k;
			cin >> j >> k;
			path[j].push_back(k);
		}
		for(int i:source)
			bfs(i);
		int count=0;
		for(int i=1; i<=n; i++)
			if(final[i].size()==source.size())
				count++;
		cout << "Case " << ++tc << ": " << count << "\n";
	}
	return 0;
}