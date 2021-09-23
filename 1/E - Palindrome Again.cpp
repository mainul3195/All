#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	int t,tc=0;
	cin >> t;
	getline(cin, s);
	while(t--)
	{
		bool ok=1;
		getline(cin, s);
		int l=0;
		for(int i=0; s[i]; i++)
			if(s[i]>='a' && s[i]<='z')
				l++;
		int tmp=sqrt(l);
		if(tmp*tmp!=l)
			ok=0;
		else
		{
			char ch[tmp][tmp];
			int k=0;
			for(int i=0; i<tmp; i++)
				for(int j=0; j<tmp; j++)
				{
					while(s[k]<'a' || s[k]>'z')
						k++;
					ch[i][j]=s[k++];
				}
		//	cout << ch[0][3];
			for(int i=0; i<=(tmp-1)/2; i++)
			{
				for(int j=0; j<tmp; j++)
				{
					if(ch[i][j] != ch[tmp-i-1][tmp-j-1])
					{
						ok=0;
						break;
					}
				}	
				if(!ok)			
					break;
			}
			for(int i=0; i<=(tmp-1)/2; i++)
			{
				for(int j=0; j<tmp; j++)
				{
					if(ch[j][i] != ch[tmp-j-1][tmp-i-1])
					{
						ok=0;
						break;
					}
				}	
				if(!ok)			
					break;
			}
			for(int i=0; i<tmp; i++)
			{
				for(int j=0; j<tmp; j++)
					if(ch[i][j]!=ch[j][i])
					{
						ok=0;
						break;
					}
				if(!ok)
					break;
			}
		}
		cout << "Case #" << ++tc << ":\n";
		if(ok)
			cout << tmp << "\n";
		else
			cout << "No magic :(\n";
	}
	return 0;
}