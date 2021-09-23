#include<bits/stdc++.h>
using namespace std;
string s[25];
int n,m, x[]={0,1,0,-1}, y[]={1, 0, -1, 0};
int dfs(pair<int, int> home)
{
	int u=home.first;
	int v=home.second;
	s[u][v]='#';
	int temp=0;
	for(int i=0; i<4; i++)
	{
		int a=u+x[i];
		int b=v+y[i];
		if(a<0 || a>=n || b<0 || b>=m || s[a][b]=='#')
			continue;
		temp += 1+dfs({a,b});
	}
	return temp;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, tc=0;
	cin >> t;
	while(t--)
	{
		cin >> m >> n;
		for(int i=0; i<n; i++)
			cin >> s[i];
		pair< int, int> home;
		bool ok=1;
		for(int i=0; i<n; i++)
			if(ok)
				for(int j=0; j<m; j++)
					if(s[i][j]=='@')
					{
						home={i,j};
						ok=0;
						break;
					}
		cout << "Case " << ++tc << ": " << dfs(home)+1 << "\n";
	}
	return 0;
}