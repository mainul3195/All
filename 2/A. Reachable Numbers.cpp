#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n<10)
	{
		cout << 9;
		return 0;
	}
	int ans=1;
	while(n/10)
	{
		int r=n%10;
		ans+=9-r;
		n/=10;
	}
	ans+=9;
	cout << ans << "\n";
	return 0;
}