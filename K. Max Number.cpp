#include<bits/stdc++.h>
using namespace std;
int mx=-1000000005;
void print(int n)
{
	if(!n)
		return;
	int x;
	cin >> x;
	if(x>mx)
		mx=x;
	print(n-1);
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	print(n);
	cout << mx;
	return 0;
}