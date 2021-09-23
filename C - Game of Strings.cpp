#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int turn=1;
	stack<char>st;
	for(int i=0; s[i]; i++)
	{
		if(!st.empty() && s[i]==st.top())
		{
			turn = !turn;
			st.pop();
		}
		else
			st.push(s[i]);
	}
	if(turn)
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}