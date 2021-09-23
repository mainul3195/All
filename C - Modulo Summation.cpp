#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int ans=0;
	for(int i=0; i<n; i++)
	{
		int j;
		cin >> j;
		ans+=j;
	}
	cout << ans-n << "\n";
	return 0;
}