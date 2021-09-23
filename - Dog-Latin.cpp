#include<bits/stdc++.h>
using namespace std;
bool vowelck(char c)
{
	switch (c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
			return 1;
		default:
			return 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	while(getline(cin,s))
	{
		for(int i=0; i<s.size(); i++)
		{
			if((s[i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i] <='Z'))
			{
				int start=i,end=i;
				while((s[++i]>='a' && s[i]<='z') ||(s[i]>='A' && s[i] <='Z'))
					end++;
				//cout << start << " " << end << "\n";
				if(vowelck(s[start]))
				{
					for(int j=start; j<=end; j++)
						cout << s[j];
					cout << "ay";
				}
				else
				{
					for(int j=start+1; j<=end; j++)
						cout << s[j];
					cout << s[start] << "ay";
				}
			}
			cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}