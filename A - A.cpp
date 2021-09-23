#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	vector<int>num;
	while (cin >> n and n)
	{
		int t;
		while(cin >> t and t)
		{
			bool ok=1;
			int mx=t;
			num.clear();
			num.push_back(t);
			for(int i=1; i<n; i++)
			{
				cin >> t;
				num.push_back(t);
			}
			for(int i=1; i<n; i++)
				if(num[i]>num[i-1])
				{
					if(num[i]<=mx)
					{
						ok=0;
						break;
					}
					mx=num[i];
				}
			if(ok)
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		cout << "\n";
	}
	return 0;
}