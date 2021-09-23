#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x=1,y=0;
		return a;
	}
	int x1,y1;
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
		int x, k, p,q;
		cin >> x >> k;
		int g=gcd(x/k, (x+k-1)/k, p, q);
	//	cout << g << " " << p << " " << q << "\n";
		p=p*x/g;
		q=q*x/g;
		cout << p << " " <<  q << '\n';
	}
	return 0;
}