#include<bits/stdc++.h>
using namespace std;
vector<int> cat(100005), node[100005];
int m,ans;
void dfs(int u, int parent, int k)
{
	if(k>m)
		return;
	if(node[u].size()==1 && node[u][0]==parent)
	{
		ans++;
		return;
	}
	for(int j: node[u])
		if(j!=parent)
		{
			if(cat[j])
				dfs(j, u, k+1);
			else
				dfs(j, u, 0);
		}
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		cin >> cat[i];
	for(int i=0; i<n-1; i++)
	{
		int j,k;
		cin >> j >> k;
		node[j].push_back(k);
		node[k].push_back(j);
	}
	dfs(1,-1,cat[1]);
	cout << ans << "\n";
	return 0;
}