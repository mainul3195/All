#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long n,m,k;
	cin >> n;
	if(n<=2)
	{
		cout << "-1";
		return 0;
	}
	if(n%2)
	{
		m=(n*n)/2;
		k=m+1;
	}
	else
	{
		m=n*n/4-1;
		k=m+2;
	}
	cout << m << " " << k;
	return 0;
}