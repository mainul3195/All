#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m,x,y,i,j,k,l;
	cin >> n >> m >> x >> y;
	cout << x << " " << y << "\n";
	for(i=1; i<=m; i++)
		if(i!=y)
			cout << x << " " << i << "\n";
	int c;
	for(i=1,j=m; i<=n ; i++)
		if(i!=x)
			for(k=1; k<=m; k++)
			{
				cout << i << " " << j << "\n";
				if(j==m)
					c=-1;
				else if(j==1)
					c=1;
				if(k!=m)
					j+=c;
			}
	return 0;
}