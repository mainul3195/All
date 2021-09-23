#include<bits/stdc++.h>
using namespace std;
vector<int> node[30],vis(30);
void dfs(int s)
{
	vis[s]=1;
	for(int i: node[s])
	{
		if(vis[i])
			continue;
		dfs(i);
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	string s;
	while(t--)
	{
		for(int i=0; i<30; i++)
			node[i].clear();
		vis.assign(30,0);
		int n;
		char c;
		cin >> c;
		n=c-64;
		getline(cin , s);
		while(getline(cin , s) and s.size())
		{
			node[s[0]-65].push_back(s[1]-65);
			node[s[1]-65].push_back(s[0]-65);
		}
		int count=0;
		for(int i=0; i<n; i++)
			if(!vis[i])
			{
				count++;
				dfs(i);
			}
		cout << count << "\n";
		if(t)
			cout << "\n";
	}
	return 0;
}