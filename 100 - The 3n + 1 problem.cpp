#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int l, h;
	while(cin >> l >> h)
	{
		int x=l, y=h;
		if(l>h)
			l^=h^=l^=h;
		int count=0;
		for(int n=l; n<=h; n++)
		{
			int c=0;
			int i=n;
			do
			{
				c++;
				if(i==1)
					break;
				else if(i&1)
					i=3*i+1;
				else
					i/=2;
			}while(1);
			count=max(count, c);
		}
		cout << x << " " <<  y << " " << count << "\n";
	}
}