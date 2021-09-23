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
		int mx=0;
		vector<int>v(n+2);
		v[0]=v[n+1]=2000000000;
		for(int i=1; i<=n; i++)
		{
			cin >> v[i];
			if(v[i]>mx)
				mx=v[i];
		}
		bool flag=1;
		for(int i=1; i<=n; i++)
			if(v[i]==mx && (v[i]>v[i-1] || v[i]>v[i+1]))
			{
				cout << i << "\n";
				flag=0;
				break;
			}
		if(flag)
			cout << "-1\n";
	}
	return 0;
}