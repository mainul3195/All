#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(0) ; cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> vn(n), vm(m);
		int totn=0, totm=0;
		for(int i=0; i<n; i++)
		{
			cin >> vn[i];
			totn+=vn[i];
		}
		for(int i=0; i<m; i++)
		{
			cin >> vm[i];
			totm+=vm[i];
		}
		sort(vn.begin(), vn.end());
		sort(vm.begin(), vm.end(), greater<int>());
		int i;
		for( i=0; totn<=totm && i<m && i<n; i++)
		{
			totn+=vm[i]-vn[i];
			totm+=vn[i]-vm[i];
		}
		if(totn>totm)
			cout << i << "\n";
		else
			cout << "-1\n";
	}
	return 0;
}