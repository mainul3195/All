#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while (n--)

	{
		int i;
		cin >> i;
		if(!(i%2))
			cout << i-1;
		else
			cout << i;
		cout << " \n"[!n];
	}
	return 0;
}