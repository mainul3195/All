#include<bits/stdc++.h>
using namespace std;
int m,n;
int x[]={0, 1, 1, 1, 0, -1, -1, -1}, y[]={1, 1, 0, -1, -1, -1, 0, 1};
string s[101];
void dfs(pair<int, int> b)
{
	s[b.first][b.second]='*';
	for(int i=0; i<8; i++)
	{
		int u=b.first + x[i];
		int v=b.second + y[i];
		if(u<0 || u>=n || v<0 || v>=m || s[u][v]=='*')
			continue;
		dfs({u,v});
	}
}
int main()
{
	while(cin >> n >> m and n)
	{
		int count=0;
		for(int i=0; i<n; i++)
			cin >> s[i];
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(s[i][j]=='@')
					dfs({i,j}), count++;
		cout << count << "\n";
	}
	return 0;
}