#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool flag=1;
	if(n&1)
		flag=0;
	for(int i=0, j=n/2; i<n/2; i++, j++)
	{
		if(s[i]!=s[j])
		{
			flag=0;
			break;
		}
	}
	if(flag)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}