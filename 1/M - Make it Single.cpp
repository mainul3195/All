#include<bits/stdc++.h>
using namespace std;
vector<int> edge[300005], child(300005);
void dfs(int start, int parent)
{
	int count=0;
	for(int i=0; i<edge[start].size(); i++)
	{
		if(edge[start][i]==parent)
			continue;
		dfs(edge[start][i], start);
		count += child[edge[start][i]];
	}
	child[start]=1+count;
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
			edge[i].clear();
		fill(child.begin(), child.begin()+n+2, 0);
		for(int i=1; i<n; i++)
		{
			int j,k;
			cin >> j >> k;
			edge[j].push_back(k);
			edge[k].push_back(j);
		}
		bool ok=1;
		dfs(1, -1);
		if(!(n&1))
		{
			for(int i=1; i<=n; i++)
			{
				if(child[i]== n/2)
				{
					int sec;
					for(int j=0; j<edge[i].size(); j++)
						if(child[edge[i][j]] > n/2)
						{
							sec=edge[i][j];
							break;
						}
					for(int j=0; j<edge[i].size(); j++)
						if(edge[i][j] != sec)
						{
							cout << i << " " << edge[i][j] << "\n" << sec << " " << edge[i][j] << "\n";
							ok=0;
							break;
						}
				}
				if(!ok)
					break;
			}
			if(ok)
				for(int i=1; i<=n; i++)
				{
					if(child[i]==n)
					{
						cout << i << " " << edge[i][0] << "\n" << i << " " << edge[i][0] << "\n";
						break;
					}
				}
		}
		else
		{
			for(int i=0; i<=n; i++)
				if(child[i]==n || child[i]==n/2+1)
				{
					cout << i << " " << edge[i][0] << "\n" << i << " " << edge[i][0] << "\n";
					break;
				}
		}
	}
	return 0;
}