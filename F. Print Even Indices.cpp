#include<bits/stdc++.h>
using namespace std;
int t;
void print(int n)
{
	if(n==t+1)
		return;
	int x;
	cin >> x;
	print(n+1);
	if(n&1)
		cout << x << " \n"[n==1];
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	print(1);
	return 0;
}