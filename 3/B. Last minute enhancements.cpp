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
		cin >> n;
		set<int> st;
		int j,k;
		cin >> j;
		st.insert(j);
		for(int i=1; i<n; i++)
		{
			cin >> k;
			if(k<j)
				continue;
			if(k==j)
				j=k+1;
			else
				j=k;
			st.insert(j);
		}
		cout << st.size() << "\n";
	}
	return 0;
}