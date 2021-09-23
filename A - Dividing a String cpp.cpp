#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int ans=1;
	string s;
	cin >> s;
	for(int i=0; i<s.size()-1; i++)
	{
		if(s[i] == s[i+1])
		{
			if(++i<s.size())
				ans++;
			continue;
		}
		ans++;
	}
	cout << ans << "\n";
	return 0;
}