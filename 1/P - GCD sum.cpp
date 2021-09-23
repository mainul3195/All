#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	if(!b)
		return a;
	return gcd(b, a%b);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	while(1)
	{
		int n;
		cin >> n;
		if(!n)
			return 0;
		long long g=0;
		for(int i=1; i<n; i++)
			for(int j=i+1; j<=n; j++)
				g+=gcd(i,j);
		cout << g << "\n";
	}
}