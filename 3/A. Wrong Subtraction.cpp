#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,k;
	cin >> n >> k;
	bool ok=1;
	while(k)
	{
		if(n%10 >= k)
		{
			cout << n-k;
			ok=0;
			break;
		}
		else
		{
			k-= (n%10 + 1);
			n/=10;
		}
	}
	if(ok)
		cout << n;
	return 0;
}