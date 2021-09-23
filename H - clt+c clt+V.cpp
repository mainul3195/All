#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,i,p,q;
		cin >> n;
		int a[3126]={0};
		int c=0;
		while(n--)
		{
			cin >> i;
			p=i/32;
			q=i%32;
			if(!(a[p] & 1 << q))
			{
				c++;
				a[p] |= 1 << q;
			}
		}
		cout << c << "\n";
	}
	return 0;
}
