#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int i, j, k, h, l, mid, ans;
	vector < int > v;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	sort(v.begin(), v.end());
	for(i=0; i<m; i++)
	{
		cin >> k;
		ans=n;
		l=0;
		h=n-1;
		while(l<=h)
		{
			mid=l+(h-l)/2;
			if(v[mid]>k)
			{
				ans=mid;
				h=mid-1;
			}
			else
				l=mid+1;
		}
		cout << ans << " \n"[i==m-1];
	}
	return 0;
}