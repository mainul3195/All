#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		double m,n,d,ans,t1,t2,temp;
		cin >> m >> n >> d;
		cout << n << " \n";
		double l=0, r=d, mid,mid2;
		while(l+.0000000001<=r)
		{
			mid=(l+r)/2;
			mid2=mid-.00000001;
			temp=d*d-mid*mid;
			if(temp<.0000000001) temp=0;
			t1=m*sqrt(temp)+n*mid;
			cout << sqrt(temp) << " " << d << " " << mid  << " " << d*d-mid*mid << "\n";
			t2=m*sqrt(temp)+n*mid2;
			if(fabs(t1-t2)<.000000001)
			{
				ans=t1;
				break;
			}
			else if(t1>t2)
				l=mid;
			else
				r=mid;
		}
		cout << fixed << setprecision(7) << ans << " " << mid <<" " << t1 << " " << t2 <<"\n";
	}
	return 0;
}