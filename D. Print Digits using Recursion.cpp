#include<bits/stdc++.h>
using namespace std;
int x;
void print(int n)
{
	if(!x)
	{
		cout << "0\n";
		return;
	}
	if(!n)
		return;
	print(n/10);
	cout << n%10 << " \n"[n==x];
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> x;
		print (x);
	}
	return 0;
}