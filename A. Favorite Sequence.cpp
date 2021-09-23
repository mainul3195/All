#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin >>  v[i];
		int f=0, l=n-1;
		for(int i=0; i<n; i++)
		{
			if(i%2)
				cout << v[l--] << " \n"[i==n-1];
			else
				cout << v[f++] << " \n"[i==n-1];
		}
	}
	return 0;	
}