#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ans=0;
	int j;
	while(n--)
	{
		cin >> j;
		while(!(j%2))
			j/=2, ans++;
	}
	cout << ans << "\n";
	return 0;
}