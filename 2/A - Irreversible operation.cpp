#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	long long ans=0, w=0;
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]=='W')
			w++;
		else
			ans+=w;
	}
	cout << ans << "\n";
	return 0;
}