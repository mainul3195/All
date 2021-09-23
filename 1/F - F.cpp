#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	priority_queue<int, vector<int>, greater<int> > q;
	int n;
	while(cin >> n and n)
	{
		for(int i=0; i<n; i++)
		{
			int j;
			cin >> j;
			q.push(j);
		}
		long long ans=0;
		while(q.size() != 1)
		{
			int a=q.top();
			q.pop();
			int b=q.top();
			q.pop();
			ans+=a+b;
			q.push(a+b);
		}
		cout << ans << "\n";
		q.pop();
	}
	return 0;
}