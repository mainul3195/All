#include<bits/stdc++.h> 
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,x,y,i,j;
		string s;
		cin >> n >> m >> x >> y;
		if(2*x<y)
			y=2*x;
		int cost=0;
		while(n--)
		{
			cin >> s;
			for(i=0; i<s.size(); i++)
			{
				int c=0;
				if(s[i]=='.')
				{
					c++;
					while(s[++i] != '*' && s[i])
						c++;
					cost += (c/2)*y + (c%2)*x;
				}
			}
		}
		cout << cost << "\n";
	}
	return 0;
}