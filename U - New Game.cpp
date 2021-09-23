#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,k,moves,i,j;
	cin >> n >> m >> k;
	moves=n-1+m-1+ n*m-1;
	cout << moves << "\n";
	for(i=1; i<m; i++)
		cout << "L";
	for(i=1; i<n; i++)
		cout << "U";
	char c;
	for(i=0; i<n; i++)
	{
		if(i%2)
			c='L';
		else
			c='R';
		for(j=1; j<m; j++)
			cout << c;
		if(i!=n-1)
			cout << "D";
	}
	return 0;
}