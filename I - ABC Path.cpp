#include<bits/stdc++.h>
using namespace std;
int h,w,x[]={1,1,1,0,-1,-1,-1,0}, y[]={1,0,-1,-1,-1,0,1,1};
vector<string> s(55);
int vis[55][55];
queue<pair<int, int>> q;
int bfs()
{
	int ans=0;
	while(!q.empty())
	{
		pair<int, int> p=q.front();
		q.pop();
		ans=max(ans, vis[p.first][p.second]);
		for(int i=0; i<8; i++)
		{
			int a=p.first + x[i];
			int b=p.second + y[i];
			if(a<0 || b<0 || a>=h || b>=w || vis[a][b])
				continue;
			if(s[a][b]==s[p.first][p.second]+1)
			{
				q.push({a,b});
				vis[a][b]=vis[p.first][p.second]+1;
			}
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc=0;
	while(cin >> h >> w and h)
	{
		memset(vis, 0, sizeof(vis));
		for(int i=0; i<h; i++)
			cin >> s[i];
		for(int i=0; i<h; i++)
			for(int j=0; j < w; j++)
				if(s[i][j]=='A')
				{
					q.push({i,j});
					vis[i][j]=1;
				}
		cout << "Case " << ++tc << ": " << bfs() << "\n";
		// for(int i=0; i<h; i++)
		// 	for(int j=0; j<w; j++)
		// 		cout << vis[i][j] << " \n"[j==w-1];
	}
	return 0;
}