#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];
		bool flag=1;
		for(int i=1; i<n; i++)
			if(v[i]>=v[i-1])
			{
				flag=0;
				break;
			}
		if(flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}