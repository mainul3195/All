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
		int n=s.size();
		vector<int> v(n, 1);
		int count=0;
		bool adj=1;
		for(int i=1; i<s.size(); i++)
		{
			if((v[i-1] && s[i]==s[i-1]) || (i>1 && v[i-2] && s[i]==s[i-2]))
			{
				v[i]=0;
				count++;
			}
		}
		cout << count << "\n";
	}
	return 0;
}