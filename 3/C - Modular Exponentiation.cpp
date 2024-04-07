#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int m,n;
	cin >> n >> m;
	int mod=1;
	bool flag=1;
	for(int i=0; i<n; i++)
	{
		mod<<=1;
		if(mod>m)
		{
			flag=0;
			break;
		}
	}
	if(flag)
		cout << m%mod;
	else
		cout << m;
	return 0;
}