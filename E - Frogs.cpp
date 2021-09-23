#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string a,s;
	while(n--)
	{
		a="R";
		cin >> s;
		a+=s;
		a+="R";
		int f=0, i, j,c=0;
		for(i=0; a[i]; i++)
			if(a[i]=='R')
			{				
				if(i-f >= c)
					c= i-f;
				f=i;
			}
		cout << c << "\n";
	}
	return 0;
}