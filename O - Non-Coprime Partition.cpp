#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,i,s,j;
	cin >> n;
	if(n<=2) cout << "No";
	else
	{
		if(n%2)
			s=(n+1)/2;
		else
			s=n/2;
		j=n-1;
		cout << "Yes\n1 " << s << "\n" << j << " ";
		for(i=1; i<=n; i++)
			if(i!=s) cout << i << " \n"[i==n];
	}
	return 0;
}