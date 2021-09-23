#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b;
	cin >> a >> b;
	a=min(a,b);
	long long ans=1;
	while(a)
		ans*=a--;
	cout << ans;
	return 0;
}