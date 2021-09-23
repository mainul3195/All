#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int ar[3];
		cin >> ar[0] >> ar[1] >> ar[2];
		sort(ar, ar+3);
		cout << ar[1] << "\n";
	}
	return 0;
}