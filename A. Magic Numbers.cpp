#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	bool ok=1;
	for(int i=0; i<s.size() ; i++)
	{
		if(s[i]=='1' && s[i+1] == '4' && s[i+2]=='4')
			i+=2;
		else if(s[i]=='1' && s[i+1] == '4')
			i+=1;
		else if(s[i]=='1')
			continue;
		else
		{
			ok=0;
			break;
		}
	}
	if(ok)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}