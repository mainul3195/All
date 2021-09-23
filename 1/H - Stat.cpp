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
		int i1,i2, j1, j2,flag=1;
		cin >> i1 >> j1;
		if(i1<j1)
			flag=0;
		for(int i=1; i<n; i++)
		{
			cin >> i2 >> j2;
			if(flag)
				if((i2-i1 < j2-j1) || i2-i1<0 || j2-j1<0)
					flag = 0;
			i1=i2;
			j1=j2;
		}
		if(flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}