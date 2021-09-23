#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int h1,m1,h2,m2,i;
	while(1)
	{
		cin >> h1 >> m1 >> h2 >> m2;
		if(!h1 && !m1 && !h2 && !m2)
			return 0;
		i=(60*h2+m2)-(60*h1+m1);
		if(i<0) i+=24*60;
		cout << i << "\n";
	}
}