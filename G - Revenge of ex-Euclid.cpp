#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x=1, y=0;
		return a;
	}
	int x1, y1;
	int g=gcd(b, a%b, x1, y1);
	x=y1;
	y=x1-(a/b)*y1;
	return g;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, p, q;
		cin >> a >> b >> c ;
		int g= gcd(a, b, p, q);
		bool flag=0;
		int m=p*c/g, n=q*c/g;
		//cout << m << " " << n << "\n";
		int cm=0, cn=0;
		while(m>0)
		{
			if(m>0 && n>0)
				cm++;
			m-=(b/g);
			n+=(a/g);
		}
		m=p*c/g, n=q*c/g;
		while(n>0)
		{
			if(m>0 && n>0)
				cn++;
			n-=(a/g);
			m+=(b/g);
		}
		//cout << g << " " << c << " " << p << " " << q <<  "\n";
		cout << max(cm, cn) << "\n";
	}
	return 0;
}