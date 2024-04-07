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
		vector<int>v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];
		bool sm=1;
		for(int i=0; i<n-1; i++)
			if(v[i]!=v[i+1])
			{
				sm=0;
				break;
			}
		if(sm)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int i=1; i<n; i++)
			for(int j=0; j<n; j++)
				if(v[i]!=v[j])
				{
					cout << j+1 << " " << i+1 << "\n";
					break;
				}
	}
	return 0;
}