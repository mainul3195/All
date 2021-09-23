#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int i,j,q;
	vector<int>v;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	sort(v.begin(), v.end());
	cin >> q;
	while(q--)
	{
		int l=0, r=n-1, mid, num, ans=0;
		cin >> num;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(v[mid]<=num)
			{
				l=mid+1;
				ans=mid+1;
			}
			else
				r=mid-1;
		}
		cout << ans << "\n";
	}
	return 0;
}