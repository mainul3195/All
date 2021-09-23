#include<bits/stdc++.h>
using namespace std;
vector<int> v[10005], starting,nodelebel[1000];
int bfs(int n, int to)
{
	queue<int>q;
	vector<int>lebel(10005,0), vis(10005,0);
	lebel[n]=0;
	vis[n]=1;
	int mxlebel=0;
	q.push(n);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		if(u==to)
			return lebel[u];
		for(int j : v[u])
		{
			if(vis[j])
			{
				nodelebel[lebel[j]].push_back(u);
				continue;
			}
			vis[j]=1;
			lebel[j]=lebel[u]+1;
			mxlebel=max(mxlebel, lebel[j]);
			q.push(j);
		}
	}
	return mxlebel;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	int tc=0;
	cin >> t;
	while(t--)
	{
		for(int i=0; i<1000; i++)
			nodelebel[i].clear();
		int n,r;
		cin >> n >> r;
		vector<int>count(n+1, 0);
		for(int i=0; i<r; i++)
		{
			int j,k;
			cin >> j >> k;
			v[j].push_back(k);
			v[k].push_back(j);
			count[j]++,count[k]++;
		}
		int s, e;
		cin >> s >> e;
		int t1=bfs(s,-1);
		//cout << t1 << " " << lastnode << " " << e << "\n";
		cout << "Case " << ++tc << ": " << t1+ max(bfs(nodelebel[t1][0], e) << "\n";
	}
	return 0;
}