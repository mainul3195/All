#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	cout<< s;
	int j,ans=0,period=0;
	for(int i=1; i<=n; i++)
	{
		for( j=0; j+i<n; j++)
			if(s[j] != s[j+i])
				break;
		if(j+i==n)
		{
			period=i;
			break;
		}
	}
	//cout << period << "\n";
	if(period!=n)
		s.erase(s.begin(), s.begin()+s.size()-period);
	for(int i=1; i<k; i++)
		cout << s;
	return 0;
}