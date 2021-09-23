#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a,b;
	cin >> a >> b;
	for(int i=0; i<a.size(); i++)
		a[i]=tolower(a[i]);
	for(int i=0; i<b.size(); i++)
		b[i]=tolower(b[i]);
	if(a<b)
		cout << "-1\n";
	else if(a>b)
		cout << "1\n";
	else
		cout << "0\n";
	return 0;
}