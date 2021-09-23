#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(1)
	{
		cin >> s;
		if(s.size()==1 && s[0]=='0')
			return 0;
		int sum,i,j,k,l,c=0;
		l=s.size();
		reverse(s.begin(), s.end());
		for(i=1; i<=l; i++)
			c+=((1<<i)-1)*(s[i-1]-'0');
		cout << c << "\n";
	}
}