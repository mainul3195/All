#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, k, d;
		cin >> n >> k >> d;
		int tot=0;
		for(int i=0; i<n; i++)
		{
			int j;
			cin >> j;
			tot+=j;
		}
		cout << min ( tot/k, d) << "\n";
	}
	return 0;
}