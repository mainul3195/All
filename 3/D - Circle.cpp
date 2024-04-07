#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q; 
	cin >> q;
	while(q--)
	{
		int n,i,j,k;
		cin >> n;
		vector <int> num;
		for(i=0; i<n; i++)
		{
			cin >> j;
			num.push_back(j);
		}
		int flag=1;
		for(i=1; i<n; i++)
			if(abs(num[i]-num[i-1])!=1 && (num[i]!=n || num[i-1]!=1) && (num[i]!=1 || num[i-1]!=n))
			{
				flag=0;
				break;
			}
		if(flag)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
	return 0;
}