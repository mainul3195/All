#include<bits/stdc++.h>
using namespace std;
void print(int n)
{
	if(!n)
		return;
	print(n-1);
	cout << n << "\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	print(n);
	return 0;
}