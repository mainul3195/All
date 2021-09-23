#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k; 
		cin >> n >> k;
		if(k>=n)
			cout << k-n << "\n";
		else
		{
			int b=(k+n)/2;
			if(b+b==k+n)
				cout <<"0\n";
			else
				cout << "1\n";
		}
	}
	return 0;
}