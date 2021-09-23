#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	int i,j,k;
	char c;
	for(i=0; i<3; i++)
	{
		if(s[i][1]=='>')
		{
			c=s[i][0];
			s[i][0]=s[i][2];
			s[i][2]=c;
		}
	}
	//for(i=0; i<3; i++) cout << s[i] << "\n";
	for(i=0; i<2; i++)
	{
		for(j=i+1; j<3; j++)
		{
			if(s[i][0]==s[j][2])
			{
				k=3-i-j;
				//cout <<s[k][0]<<s[j][0] << s[k][2]<<s[i][2]<<"\n";
				if(s[k][0]==s[j][0] && s[k][2]==s[i][2])
				{
					cout << s[j][0] << s[j][2] << s[i][2];
					return 0;
				}
				cout << "Impossible";
				return 0;
			}
		}
	}
	for(j=0; j<2; j++)
	{
		for(i=j+1; i<3; i++)
		{
			if(s[i][0]==s[j][2])
			{
				k=3-i-j;
				if(s[k][0]==s[j][0] && s[k][2]==s[i][2])
				{
					cout << s[j][0] << s[j][2] << s[i][2];
					return 0;
				}
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Impossible";
	return 0;
}