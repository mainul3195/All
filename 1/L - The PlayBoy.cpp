#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	vector<int> v;
	cin >> n;
	int i,j;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	int q;
	cin >> q;
	while(q--)
	{
		int num;
		cin >> num;
		long long l=0, r=n-1, ans=-1,mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(v[mid]<num)
			{
				ans=v[mid];
				l=mid+1;
			}
			else
				r=mid-1;
		}	
		if(ans==-1)
			cout << "X ";
		else
			cout << ans << " ";
		l=0, r=n-1, ans=-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(v[mid]>num)
			{
				ans=v[mid];
				r=mid-1;
			}
			else
				l=mid+1;
		}	
		if(ans==-1)
			cout << "X\n";
		else
			cout << ans << "\n";
	}
	return 0;
}