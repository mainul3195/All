#include<bits/stdc++.h>
using namespace std;
vector<int> node[200005],parent(200005);
int last,mx=-1;
int ans1=-1,ans2,ans3;
void dfs(int nd, int len)
{
	if(len>mx)
	{
		last=nd;
		mx=len;
	}
	for(int i: node[nd])
		if(i!=parent[nd] && i!=ans1)
		{
			parent[i]=nd;
			dfs(i, len+1);
		}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for(int i=1; i<n; i++)
	{
		int j,k;
		cin >> j >> k;
		node[j].push_back(k);
		node[k].push_back(j);
	}

	parent[1]=-1;
	dfs(1, 0);

	parent.clear();
	mx=-1;
	ans1=last;
	parent[last]=-1;
	dfs(last, 0);

	int temp=ans2=last;
	set<int> st;
	while(parent[temp] !=-1)
	{
		st.insert(parent[temp]);
		temp = parent[temp];
	}

	parent.clear();
	mx=-1;
	ans2=last;
	parent[last]=-1;
	dfs(last, 0);
	temp=ans3=last;
	st.insert(last);
	while(parent[temp] !=-1)
	{
		st.insert(parent[temp]);
		temp = parent[temp];
	}
	// for(auto i: st)
	// 	cout << i << "\n";
	cout << st.size()-1 << "\n" << ans1 << " " << ans2 << " " << ans3 << "\n";
	return 0;
}