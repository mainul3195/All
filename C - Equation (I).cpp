#include<bits/stdc++.h>
using namespace std;
int p,q,r,s,t,u;
double calc(double x)
{
	return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(cin >> p >> q >> r >> s >> t >> u)
	{
		if(calc(0) * calc(1) >0)
		{
			cout << "No solution\n";
			continue;
		}
		double h=1,l=0,mid;
		while(l+.00000001<h)
		{
			mid=(l+h)/2;
			if(calc(l)*calc(mid)<=0)
				h=mid;
			else 
				l=mid;
		}
		cout << fixed << setprecision(4) << mid << "\n";
	}
	return 0;
}