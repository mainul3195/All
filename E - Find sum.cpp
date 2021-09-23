#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	while(cin >> t)
	{
		vector <int> v;
		int i,j,k;
		for(i=0; i<t; i++)
		{
			cin >> j;
			v.push_back(j);
		}
		sort(v.begin(), v.end());
		cin >> k;
		int a,b;
		for(i=0, j=v.size()-1; i<j; )
		{
			if(v[i]+v[j]==k)
			{
				a=v[i];
				b=v[j];
				//cout << a << " " << b << "\n";
				i++;
				j--;
			}
			else if(v[i]+v[j]<k)
				i++;
			else 
				j--;
		}
		cout << "Peter should buy books whose prices are "<< a << " and " << b << ".\n\n";
	}
}