#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int a,b;
		int x,y,n;
		cin >> a >> b >> x >> y >> n;
		if(b<a)
		{
			if(b-min(n, b-y) < a-min(n, a-x))
			{
				int d=min(n,b-y);
				b-=d;
				n-=d;
				int t=min(n,a-x);
				a-=t;
			}
			else
			{
				int d=min(n,a-x);
				a-=d;
				n-=d;
				int t=min(n, b-y);
				b-=t;			
			}
		}
		else if(a<b)
		{
			if(b-min(n, b-y) < a-min(n, a-x))
			{
				int d=min(n,b-y);
				b-=d;
				n-=d;
				int t=min(n,a-x);
				a-=t;
			}
			else
			{
				int d=min(n,a-x);
				a-=d;
				n-=d;
				int t=min(n, b-y);
				b-=t;			
			}

		}
		else
		{
			if(y<x)
			{
				int d=min(n,b-y);
				b-=d;
				n-=d;
				int t=min(n,a-x);
				a-=t;
			}
			else
			{
				int d=min(n,a-x);
				a-=d;
				n-=d;
				int t=min(n, b-y);
				b-=t;
			}
		}
		long long ans=(long long)a*b;
		cout << ans << "\n";
	}
	return 0;
}