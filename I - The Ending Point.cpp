#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x, y;
	string s;
	cin >> x >> y >> s;
	for(int i=0; s[i]; i++)
	{
		if(s[i]=='U')
			y++;
		else if(s[i]=='D')
			y--;
		else if(s[i]=='R')
			x++;
		else
			x--;
	}
	cout << x << " " << y;
	return 0;
}