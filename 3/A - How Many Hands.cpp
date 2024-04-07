#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h,m;
	char c;
	while((cin >> h >> c >> m )&&(h || m))
	{
		double ans=fabs((11*m-60*h)/2.0);
		if(ans>180)
			ans=360-ans;
		cout << fixed << setprecision(3) << ans << "\n";
	}
	return 0;
}