#include<bits/stdc++.h>
using namespace std;
		int a,b,c ;
double calc(double x)
{
	return a*x+b*sin(x)-c;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> c;
		double l,h, mid=0;
		if(c>0)
			l=0, h=2*c;
		else
			l=2*c, h=0;
		while(l+.000000001<h)
		{
			mid=(l+h)/2;
			if(calc(l)*calc(mid)<=0)
				h=mid;
			else 
				l=mid;
		}
		cout << fixed << setprecision(6) << mid << "\n";
	}
	return 0;
}