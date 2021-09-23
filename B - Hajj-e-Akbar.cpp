#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc=0;
	string s;
	while (cin >> s and s!="*")
	{
		cout << "Case " << ++tc << ": ";
		if(s=="Hajj")
			cout << "Hajj-e-Akbar\n";
		else
			cout << "Hajj-e-Asghar\n";
	}
	return 0;
}