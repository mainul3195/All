#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int ar[27]={0}, i, j=0;
		string s;
		cin >> s;
		for(i=0; s[i]; i++)
		{
			if(!ar[s[i]-'a'])
			{
				j++;
				ar[s[i]-'a']=1;
			}
		}
		cout << j << "\n";
	}
	return 0;
}