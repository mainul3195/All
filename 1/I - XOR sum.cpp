#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		int n;
		cin >> n;
		char c, t[3]="a\0";
		string a,b;
		int flag=1;
		for(int i=0; i<n; i++)
		{
			cin >> c;
			if(flag)
			{
				if(c=='0')
				{
					a.insert(i, "0");
					b.insert(i, "0");
				}
				else if(c=='2')
				{
					a.insert(i, "1");
					b.insert(i, "1");
				}
				else
				{
					flag=0;
					a.insert(i, "1");
					b.insert(i, "0");
				}
			}
			else
			{
				t[0]=c;
				a.insert(i, "0");
				b.insert(i, t);
			}
		}
		cout << a << "\n" << b << "\n";
	}
	return 0;
}