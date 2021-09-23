#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	string s;
	getline(cin,s);
	for(int tc=1; tc<=t; tc++)
	{
		getline(cin,s);
		int i,j=0,l;
		l=s.size();
		char c[l];
		for(i=0; s[i]; i++)
			if(s[i]>='a' && s[i] <= 'z')
				c[j++]=s[i];
		c[j]=0;
		//cout << c << " " << j << "\n";
		i=sqrt(j);
		if(i*i != j)
		{
			cout << "Case #" << tc << ":\nNo magic :(\n";
			continue;
		}
		l=0;
		for(i=0; i<j/2; i++)
			if(c[i]!=c[j-i-1])
			{
				l=1;
				break;
			}
		if(l)
			cout << "Case #" << tc << ":\nNo magic :(\n";
		else
		{
			i=sqrt(j);
			cout << "Case #" << tc << ":\n" << i << "\n";
		}
	}
	return 0;
}