#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,q;
	cin >> n >> q;
	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin >> v[i];
	while(q--)
	{
		int d;
		cin >> d;
		deque<int> dq;
		dq.push_back(v[0]);
		for(int i=1; i<d; i++)
		{
			while(!dq.empty() && dq.back()<=v[i])
				dq.pop_back();
			dq.push_back(v[i]);
		}
		int mn=dq.front();
		for(int i=d; i<n; i++)
		{
			while(!dq.empty() && dq.back()<=v[i])
				dq.pop_back();
			if(!dq.empty() && dq.front()==v[i-d])
				dq.pop_front();
			dq.push_back(v[i]);
			mn=min(mn, dq.front());
		}
		cout << mn << "\n";
	}
	return 0;
}