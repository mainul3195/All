#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int r=0;
		int d=n%10;
		while(n)
		{
			r++;
			n/=10;
		}
		//cout << d << " " << r << "\n";
		cout << (d-1)*10 + (r*(r+1))/2 << "\n";
	}
	return 0;
}