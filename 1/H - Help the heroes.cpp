#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int x[4]={0,1,0,-1},y[4]={1,0,-1,0};
int dis[25][25], vis[25][25],n,m;
string s[25];
int bfs(pii &home)
{
	int ans=1;
	queue< pii > q;
	q.push(home);
//	dis[home.first][home.second]=0;
	vis[home.first][home.second]=1;

	while(!q.empty())
	{
		pii cur=q.front();
		q.pop();
		for(int i=0; i<4; i++)
		{
			int a=cur.first+x[i];
			int b=cur.second+y[i];
			if(a<0 || a>=m || b<0 || b>=n || s[a][b]=='#' || vis[a][b])
				continue;
			vis[a][b]=1;
			//dis[a][b]=dis[cur.first][cur.second]+1;
			// if(s[a][b]=='a'|| s[a][b]=='b' || s[a][b]=='c')
			// 	ans=dis[a][b];
			ans++;
			q.push({a,b});
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t,tc=0;
	cin >> t;
	while(t--)
	{
		//memset(dis, 0, sizeof(dis));
		memset(vis,0,sizeof(vis));
		cin >> n >> m;
		for(int i=0; i<m; i++)
			cin >> s[i];
		pair<int, int>home;
		bool ok=1;
		for(int i=0; i<m && ok; i++)
			for(int j=0; j<n; j++)
				if(s[i][j]=='@')
				{
					home={i,j};
					ok=0;
					break;
				}
		cout << "Case " << ++tc << ": " << bfs(home) << "\n";
	}
	return 0;
}