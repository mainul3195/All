#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin >> s;
	int i,count=0;
	for(i=0; s[i]; i++)
		if(s[i]=='1')
			for(; s[i]; i++)
				if(s[i]=='0')
					count++;
	if(count > 5) cout << "yes";
	else cout << "no";
	return 0;
}