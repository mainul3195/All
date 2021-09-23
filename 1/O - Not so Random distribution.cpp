#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<int> node[100005], child(100005);
vector<long long> vis;
void dfs(int n, int parent)
{
	int count=0;
	for( int i : node[n])
	{
		if(i==parent)
			continue;
		dfs(i, n);
		count += child[i];
	}
	child[n]=count+1;
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i=0; i<=n; i++)
			node[i].clear(),child[i]=0;
		vis.clear();
		for(int i=0; i<n-1; i++)
		{
			int u,v;
			cin >> u >> v;
			node[v].push_back(u);
			node[u].push_back(v);
		}
		int m;
		cin >> m;
		vector<int> pd(m),finalpd;
		for(int i=0; i<m; i++)
			cin >> pd[i];
		sort(pd.begin(), pd.end());
		if(m<n-1)
		{
			for(int i=0, l=n-1-m; i<l; i++)
				finalpd.push_back(1);
			for(int i=0; i<m; i++)
				finalpd.push_back(pd[i]);
		}
		else
		{
			for(int i=0; i<n-2; i++)
				finalpd.push_back(pd[i]);
			long long ans=1;
			sort(finalpd.begin(), finalpd.end());
			for(int i=n-2; i<m; i++)
				ans = (ans*pd[i]) % mod;
			finalpd.push_back(ans);
		}
		dfs(1, -1);
		for(int i=1; i<=n; i++)
			if(child[i] != n)
				vis.push_back((long long)child[i]*(n-child[i]));
			sort(vis.begin(), vis.end());
		long long final=0;
		for(int i=0; i<n-1; i++)
			final = (final + vis[i] * finalpd[i]) %mod;
		cout << final << "\n";
	// 	cout << "\t" << finalpd.size() << " " << vis.size() << "\n";
	// 	for(int i=0; i<finalpd.size(); i++)
	// 	cout << finalpd[i]  << " " << vis[i] << "\n";
	// cout << "\n";

	}
	return 0;
}