#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		set<int>st;
		for(int i=0; i<n; i++)
		{
			int j;
			cin >> j;
			st.insert(j);
		}
		int sz=st.size();
		//cout << "\t" << sz << "\n";
		if(k==1 && sz>k)
			cout << "-1\n";
		else if(k==1 && sz==1)
			cout << "1\n";
		else
			cout << 1+(max(0,sz-2))/(k-1) << "\n";
	}
	return 0;
}