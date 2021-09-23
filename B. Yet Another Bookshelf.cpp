#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int sum=0, left=-1;
		for(int i=0; i<n; i++)
		{
			int d;
			cin >> d;
			if(left==-1 && d)
			{
				left=i;
				continue;
			}
			if(d)
			{
				sum+= i-left-1;
				left=i;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}