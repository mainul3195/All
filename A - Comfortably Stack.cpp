#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	queue<int> st;
	cin >> t;
	while(t--)
	{
		int e,n;
		cin >> e;
		if(e==1)
		{
			cin >> n;
			st.push(n);
		}
		else if(e==2 && !st.empty())
			st.pop();
		else if(e==3)
		{
			if(st.empty())
				cout << "Empty!\n";
			else
				cout << st.front() << "\n";
		}
	}
	return 0;
}