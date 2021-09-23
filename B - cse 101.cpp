#include<bits/stdc++.h>
using namespace std;
int a[1000003];
int main()
{
	char s[1000003];
	int len, i, j=0,n, l, r;
	while(~scanf("%s", s))
	{
		a[0]=0;
		//while(s[++len]);
		for(i=0; s[i]; i++)
			a[i+1]= s[i]%2 + a[i];
		cin >> n;
		j++;
		cout << "Case " << j << ":\n";
		while(n--)
		{
			cin>> l >> r;
			if(l>r) l^=r^=l^=r;
			if(a[r+1]-a[l] == r-l+1 || a[r+1]-a[l] == 0)
				cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}