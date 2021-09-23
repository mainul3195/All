#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, i=0, a, c=0;
		cin >> n >> k;
		while(i++<n)
		{
			cin >> a;
			if(!(a%2))
				c++;
		}
		//cout << k << " " << c << " ";
		if((k && k<=c) || (!k && c<n))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}