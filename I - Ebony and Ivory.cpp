#include<bits/stdc++.h>
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
	int a, b, c, p, q;
	cin >> a >> b >> c ;
	int g= gcd(a, b, p, q);
	bool flag=0;
	int m=p*c/g, n=q*c/g;
	//cout << m << " " << n << "\n";
	if(m<0)
	{
		while(m<0)
			m+=(b/g),n-=(a/g);
		if(n<0)
			flag=1;
	}
	else if(n<0)
	{
		while(n<0)
			n+=(a/g), m-=(b/g);
		if(m<0)
			flag=1;
	}
	//cout << g << " " << c << " " << p << " " << q <<  "\n";
	if(c%g || flag)
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
}