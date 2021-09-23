#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int>v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		vector<int>::iterator it=lower_bound(v.begin(), v.end(), x);
		if(v[it-v.begin()]==x)
			cout << "Yes ";
		else
			cout << "No ";
		cout << it-v.begin()+1 << "\n";
	}
	return 0;
}