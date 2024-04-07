#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,x,y;
		cin >> n >> x >> y;
		int i,c=0,d;
		for(i=n-1; ((y-x)/i)*i != y-x; i--);
			i=(y-x)/i;
		for(d=y; d>=1 && c<n; d-=i)
		{
			c++;
			cout << d << " \n"[c==n];
		}
		for(d=y+i; c<n; d+=i)
		{
			c++;
			cout << d << " \n"[c==n];
		}
	}
	return 0;
}