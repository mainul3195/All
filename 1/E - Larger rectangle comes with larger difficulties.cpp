#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin >> n && n)
	{
		vector<int> v(n+1);
		for(int i=0; i<n; i++)
			cin >> v[i];
		v[n]=0;
		stack<int> pst, hst;
		long long area=0;
		for(int i=0; i<=n; i++)
		{
			int prepos=10000000;
			while(!pst.empty() && v[i]<hst.top())
			{
				int htop=hst.top();
				int ptop=pst.top();
				prepos=ptop;
				area=max(area, ((long long)i-ptop)*htop);
				hst.pop();
				pst.pop();
			}
			if(pst.empty() || v[i]>hst.top())
			{
				hst.push(v[i]);
				pst.push(min(i, prepos));
			}
		}
		cout << area << "\n";
	}
	return 0;
}