#include<bits/stdc++.h>
using namespace std;
int mod(int a, int b, int n)
{
	if(b==0)
		return 1;
	int tmp=mod(a, b/2, n);
	tmp*=tmp;
	if(b&1)
		tmp*=a;
	return tmp%n;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b;
		cin >> a >> b;
		cout << mod(a, b, 10) << "\n";
	}
}