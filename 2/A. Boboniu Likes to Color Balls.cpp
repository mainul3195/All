#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int r,g,b,w,e=0,o=0;
		cin >> r >> g >> b >> w;
		if(r%2)
			o++;
		else 
			e++;
		if(g%2)
			o++;
		else 
			e++;
		if(b%2)
			o++;
		else 
			e++;
		if(w%2)
			o++;
		else 
			e++;
		if(!o || o==1 || (o==3 && (r && g && b)) || o==4)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}