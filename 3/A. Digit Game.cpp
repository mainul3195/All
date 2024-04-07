#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n, e=0, o=0;
		cin >> n;
		string s;
		cin >> s;
		for(int i=0; s[i]; i++)
		{
			if(!(i%2) && !(s[i]%2))
				e++;
			else if( i%2 && s[i]%2)
				o++;
		}
	//	cout << e << " " << o << "\n";
		bool flag;
		if(!(s.size()%2))
		{
			if(o<n/2)
				flag=0;	
			else
				flag=1;
		}

		else if(s.size()%2)
		{
			if(e<=n/2)
				flag=1;	
			else 
				flag=0;
		}

		if(flag)
			cout << "1\n";
		else
			cout << "2\n";
	}
	return 0;
}