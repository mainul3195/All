#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int ans=1000000000,h,c,i,t,temp;
		cin >> h >> c >> t;
		if((c+h)/2 == t)
		{
			cout << "2\n";
			continue;
		}
		int l=0, r=1000000000, m;
		double x,min=1000000000.0;
		while(l<=r)
		{
			m=(l+r)/2;
			x=(m*(double)(c+h)+h)/(2*m+1);
			//cout << "x="<<fixed << setprecision(9) << x <<"\nm=" << m << "\nl=" << l << "\nr=" << r << "\n\n";

			if(fabs(t-x)==min)
			{
				min=fabs(t-x);
				temp=2*m+1;
				if(temp<ans)ans=temp;
			}
			else if(fabs(t-x)<min)
			{
				min=fabs(t-x);
				ans=2*m+1;
			}
			if(x>t)
				l=m+1;
			else
				r=m-1;
		}
		if(fabs(t-(c+h)/2.0)<=min)
			ans=2;
		cout << ans << "\n";
	}
	return 0;
}