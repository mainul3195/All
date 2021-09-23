#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i=0; i<t; i++)
	{
		int n,ck=1;
		int tot=0;
		string s;
		cin >> n;
		for(int j=0; j<n; j++)
		{
			cin >> s;
			if(s=="donate")
			{
				int d;
				cin >> d;
				tot+=d;
			}
			else
			{
				if(ck)
				{
					ck=0;
					cout << "Case " << i+1 << ":\n";
				}
				cout << tot << "\n";
			}

		}
	}
	return 0;
}