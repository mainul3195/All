#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		if(!next_permutation(s.begin(), s.end()))
			cout << "no answer\n";
		else
			cout << s << "\n";
	}
	return 0;
}