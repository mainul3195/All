#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> vis(9, vector<int> (9,0));
int x[]={1,2,2,1,-1,-2,-2,-1}, y[]={2,1,-1,-2,-2,-1,1,2};
int bfs(pair<int, int> s, pair< int, int> e)
{
	vis[s.first][s.second]=1;
	queue<pair<int, int> > q;
	pair<int, int> p;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front().first;
		int v=q.front().second;	
		q.pop();
		for(int i=0; i<8; i++)
		{
			int a=u+x[i];
			int b=v+y[i];
			if(a<0 || b<0 || a>7 || b>7 || vis[a][b])
				continue;
			vis[a][b]=vis[u][v]+1;
			if(a==e.first && b==e.second)
				return vis[a][b]-1;
			q.push({a,b});
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		for(int i=0; i<9; i++)
			fill(vis[i].begin(), vis[i].end(), 0);
		pair<int, int> s,e;
		char a,b;
		int x,y;
		cin >> a >> x >> b >> y;
		s={a-97, x-1};
		e={b-97, y-1};
		cout << bfs(s,e) << "\n";
	}
	return 0;
}