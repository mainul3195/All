#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		vector < int> num;
		cin >> n;
		int i,j,flag=1;
		long long sum1=0,sum2=0;
		for(i=0; i<n; i++)
		{
			cin >> j;
			num.push_back(j);
		}
		for(i=0, j=n-1; i<n; i++, j--)
		{
			sum1+=num[i];
			sum2+= num[j];
			if(sum1<=0 || sum2<=0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
			cout << "YES\n";
		else 
			cout << "NO\n";
	}
	return 0;
}