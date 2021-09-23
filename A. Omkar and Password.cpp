#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,i,j;
		cin >> n;
		vector <int> num;
		for(i=0; i<n ;i++)
		{
			cin >> j;
			num.push_back(j);
		}
		int flag=1;
		for(i=1; i<n ;i++)
			if(num[i]!=num[i-1])
				flag=0;
		if(flag)
			cout << n << "\n"; 
		else
			cout << "1\n";
	}
	return 0;
}