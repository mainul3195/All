#include<bits/stdc++.h>
using namespace std;
int m,n;
int x[]={0, 1, 1, 1, 0, -1, -1, -1}, y[]={1, 1, 0, -1, -1, -1, 0, 1};
string s[101];
int dfs(pair<int, int> b)
{
	s[b.first][b.second]='0';
	int dist=0;
	for(int i=0; i<8; i++)
	{
		int u=b.first + x[i];
		int v=b.second + y[i];
		if(u<0 || u>=n || v<0 || v>=m || s[u][v]=='0')
			continue;
		dist += 1+dfs({u,v});
	}
	return dist;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	getline(cin, s[0]);
	getline(cin, s[0]);

	while(t--)
	{
		n=0;
		while(getline(cin, s[n]) && s[n++].size());
		m=s[0].size();
		n--;
		int ans=0;
		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				if(s[i][j]=='1')
					ans=max(ans,1+dfs({i,j}));
		cout << ans << "\n";
		if(t)
			cout << "\n";
	}
	return 0;
}