#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int lim=n/4;
		int ind=0;
		for(int i=0; i<lim ;i++)
		{
			int pos = 8*(s[ind++]-48) + 4*(s[ind++]-48) + 2*(s[ind++]-48) + 1*(s[ind++]-48);
			cout << (char)(pos+97);
		}
		cout << "\n";
	}

	return 0;
}