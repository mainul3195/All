#include<iostream>
using namespace std;
#define m 1000000007
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	long long ans=1;
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
		ans = (ans*i)%m;
	cout << ans << "\n";
	return 0;
}