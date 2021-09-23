#include<bits/stdc++.h>
using namespace std;
	int n;
void print(int x)
{
	if(x==n+1)
		return;
		print(x+1);
	int i;
	for(i=0; i<n-x; i++)
		cout << " ";
	for(i=0; i<2*x-1; i++)
		cout << "*";
	cout << "\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	print(1);
	return 0;
}