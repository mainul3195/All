#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q,i,j;
	vector <int> v;
	cin >> n >> q;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	int h,l,ans,mid;
	for(i=0; i<q; i++)
	{
		int x;
		cin >> x;
		l=0;
		h=v.size()-1;
		ans=-1;
		while(l<=h)
		{
			mid=l+(h-l)/2;
			if(v[mid]>=x)
			{
				h=mid-1;
				if(v[mid]==x)
					ans=mid;
			}
			else
				l=mid+1;
		}
		cout << ans << "\n";
	}
	return 0;
}