#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
	if(!n)
		return;
	print(n/2);
	cout << n%2;
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(!n)
			cout << "0";
		else
			print(n);
		cout << "\n";
	}
	return 0;
}