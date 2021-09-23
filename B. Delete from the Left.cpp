#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s, t;
	cin >> s >> t;
	int a=0;
	for(int i=s.size()-1, j=t.size()-1; i>=0 && j>=0; i--, j--)
	{
		if(s[i]!=t[j])
			break;
		else
			a++;
	}
	cout << s.size()+t.size()-2*a;
	return 0;
}