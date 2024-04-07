#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; 
	cin >> n;
	vector <int> v;
	v.push_back(0);
	int i,r,l;
	for(i=0; i<n; i++)
	{
		cin >> r;
		l=r+v[i];
		v.push_back(l);
	}
	int q;
	cin >>q;
	while(q--)
	{
		cin >> r >> l;
		if(l<r)
			l^=r^=l^=r;
		i=v[l+1]-v[r];
		cout << i << "\n";
	}
	return 0;
}