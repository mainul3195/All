#include<bits/stdc++.h>
using  namespace std;
int findans(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	int x1,y1;
	int g=findans(b, a%b, x1, y1);
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
		int a, m;
		cin >> a >> m;
		int ans,y;
		int g=findans(a,m,ans, y);
		ans=(ans+m)%m;
		//cout << g << " " << ans << "\n";
		if(g==1 && !ans)
			ans=m;
		else if(g!=1)
			ans=0;
		if(ans)
			cout << ans << "\n";
		else
			cout << "Not Exist\n";
	}
	return 0;
}