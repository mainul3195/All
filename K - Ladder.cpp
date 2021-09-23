#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	int i=0;
	while(t--)
	{
		double x,y,c,l,r,mid,h;
		cin >> x >> y >> c;
		l=0, r=min(x,y);
		while(l+.000000001<r)
		{
			mid=(l+r)/2;
			h=(sqrt((x*x-mid*mid)*(y*y-mid*mid))/(sqrt(x*x-mid*mid)+ sqrt(y*y-mid*mid)));
			if(h>c)
				l=mid;
			else
				r=mid;
		}
		cout << "Case " << ++i << ": " << fixed<< setprecision(8) << mid << "\n";
	}
	return 0;
}