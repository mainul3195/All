#include<bits/stdc++.h>
using namespace std;
int n, x[]={-1,-1,0,0,1,1}, y[]={-1,0,-1,1,0,1};
bool ok;
vector<string> s(202);
int dfs(int u, int v)
{
	s[u][v]='w';
	for(int i=0; i<6; i++)
	{
		int a=u+x[i];
		int b=v+y[i];
		if(a<0 || b<0 || a>=n || b>=n || s[a][b]=='w')
			continue;
		if(a==n-1)
			ok=1;
		dfs(a,b);
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=0;
	while(cin >> n and n)
	{
		ok=0;
		for(int i=0; i<n; i++)
			cin >> s[i];
		bool done=0;
		for(int i=0; i<s[0].size(); i++)
			if(s[0][i]=='b' && dfs(0,i) && ok)
			{
				done=1;
				break;
			}
		cout << ++t << " ";
		if(done)
			cout << "B\n";
		else
			cout << "W\n";
	}
	return 0;
}