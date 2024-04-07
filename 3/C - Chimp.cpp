#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, i, q, j;
	cin >> n;
	vector <int> v;
	for(i=0; i<n; i++)
	{
		cin >> j;
		v.push_back(j);
	}
	cin >> q;
	while(q--)
	{
		int l=0, h=n-1, mid;
		cin >> j;
		while(l<=h)
		{
			mid=(l+h)/2;
			if(v[mid]>=j)
				h=mid-1;
			else
				l=mid+1;
		}
		if(h==-1) cout << "X ";
		else cout << v[h] << " ";
		l=0,h=n-1;
		while(l<=h)
		{
			mid=(l+h)/2;
			if(v[mid]<=j)
				l=mid+1;
			else
				h=mid-1;
		}
		if(l==n) cout << "X\n";
		else cout << v[l] << "\n";
	}
	return 0;
}