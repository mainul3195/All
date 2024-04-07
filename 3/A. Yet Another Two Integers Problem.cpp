#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int a,b;
		cin >> a >> b;
		int d=abs(a-b);
		d=(d+9)/10;
		cout << d << "\n";
	}
	return 0;
}