#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	stack<char> st;
	int ans = 0;

	for(auto i: s)
	{
		if(i=='(')
			st.push(i);
		else if(!st.empty())
		{
			st.pop();
			ans += 2;
		}
	}
	cout << ans << "\n";
	return 0;
}