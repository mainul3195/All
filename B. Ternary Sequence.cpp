#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int x1,y1,z1,x2,y2,z2,ans=0;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		int temp=min(z1, y2);
		ans+=2*temp;
		z1-=temp;
		y2-=temp;
		temp=min(x1,z2);
		x1-=temp;
		z2-=temp;
		ans-=2*min(y1, z2);
		cout << ans << "\n";
	}
	return 0;
}