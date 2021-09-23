/// Find nCr using recursion:
#include<bits/stdc++.h>
using namespace std;
int mem[31][31]={0};
int ncr(int n, int r)
{
	if(n<r)
		return 0;
	if(!r || r==n)
		return 1;

	if(mem[n][r])
		return mem[n][r];
	mem[n][r]=ncr(n-1, r-1)+ncr(n-1, r);
	return mem[n][r];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, r;
	cin >> n >> r;
	cout << ncr(n,r);
	return 0;
}
