#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int ans=0;
	for(int i=0; i<n; i++)
	{
		int count=0;
		if(s[i]=='x')
		{
			count++;
			while(++i<n && s[i]=='x')
			{
				count++;
			}
			if(count>2)
				ans+=count-2;
		}
	}
	cout << ans << "\n";
	return 0;
}