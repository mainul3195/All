#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	cin>>s;
	int i,j,k;
	for(i=0; s[i]; i++)
	{
		if(s[i]=='E' && s[i+1]=='G' && s[i+2]=='Y' && s[i+3]=='P' && s[i+4]=='T')
		{
			cout << " ";
			i+=4;
		}
		else cout << s[i];
	}
	return 0;
}