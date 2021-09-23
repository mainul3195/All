#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin >> n && n)
	{
		string s;
		while(n)
		{
			s=(n%2? "1" : "0")+s;
			n/=2;
		}
		int l=0;
		for(int i=0; s[i]; i++)
			if(s[i]=='1')
				l++;
		cout << "The parity of " << s << " is " << l << " (mod 2).\n";
	}
	return 0;
}