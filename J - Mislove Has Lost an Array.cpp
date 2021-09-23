#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	int i,pmin=1, pmax=1, l, r, n, min, max;
	cin >> n >> r >> l;
	for(i=0; i<r; i++)
		pmin*=2;
	for(i=0; i<l; i++)
		pmax*=2;
	//cout << pmin << " " << pmax << " " << r << " " << l << "\n";
	min = (pmin-1) + n-r;
	max = pmax-1 + (n-l)*(pmax/2);
	cout << min << " " << max;
	return 0;
}