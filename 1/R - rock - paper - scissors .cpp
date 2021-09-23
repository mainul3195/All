#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a,b,c;
	cin >> a >> b >> c;
	char f=a[0], m=b[0], s=c[0];
	if((f=='r' && m=='s' && s=='s') || (f=='p' && m=='r' && s=='r') || (f=='s' && m=='p' && s=='p'))
		cout << "F";
	else if((f=='s' && m=='r' && s=='s') || (f=='r' && m=='p' && s=='r') || (f=='p' && m=='s' && s=='p'))
		cout << "M";
	else if((f=='s' && m=='s' && s=='r') || (f=='r' && m=='r' && s=='p') || (f=='p' && m=='p' && s=='s'))
		cout << "S";
	else cout << "?";
	return 0;
}