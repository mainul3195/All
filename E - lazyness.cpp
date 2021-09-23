#include<bits/stdc++.h>
using namespace std;
#define pi (2*acos(0.0))
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, k, t;
	cin >> n >> k >> t;
	int perp=2*t/n;
	double theta=(pi*(n-perp))/(2.0*n);
	double rmax=(double)k/cos(theta);
	perp+=2;
	theta=(pi*(n-perp))/(2.0*n);
	double rmin=k/cos(theta);
	cout << fixed << setprecision(9) << rmin << " " << rmax << "\n";
	return 0;
}