#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		bool ok=1;
		for(int i=0; i<(1+s.size())/2-1 ; i++){
			if(abs(s[i]-s[i+1]) != abs(s[s.size()-i-1] - s[s.size()-2-i]))
			{
				ok=0;
				break;
			}
		}
		if(ok)
			cout << "Funny\n";
		else
			cout << "Not Funny\n";
	}
	return 0;
}