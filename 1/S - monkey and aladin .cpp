#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	for(int j=1; j<=t; j++)
	{
		int i,n,max=0, tm,d,k=0;
		cin >> n;
		vector <int> v;
		for(i=0; i<n; i++)
		{
			cin >> d;
			v.push_back(d-k);
			if(d-k>max)
				max=d-k;
			k=d;
		}
		tm=max;
		for(i=0; i<n; i++)
		{
			if(v[i]==tm)
				tm--;
			else if(tm<v[i])
			{
				max++;
				break;
			}
		}
		//cout << tm << " ";
		cout << "Case " << j << ": " << max << "\n";
	}
	return 0;
}