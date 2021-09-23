#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t,n,k,i,j;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		vector <int> v, p(n+1, 0);
		for(i=0; i<n; i++)
		{
			cin >> j;
			v.push_back(j);
		}
		for(i=1; i<n-1; i++)
			if(v[i]>v[i-1] && v[i]>v[i+1])
				p[i+1]=1;
		for(i=1; i<=n; i++)
			p[i]+=p[i-1];
		int ind=1,val=0;
		for(i=k; i<=n; i++)
			if(p[i-1]-p[i-k+1]>val)
			{
				val=p[i-1]-p[i-k+1];
				ind=i-k+1;
			}
		val++;
		cout << val << " " << ind << "\n";
	}
	return 0;
}