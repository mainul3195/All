#include<iostream>
#include<queue>
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
		priority_queue<long long, vector<long long>, greater<long long> > q;
		for(int i=0; i<n; i++)
		{
			int j;
			cin >> j;
			q.push(j);
		}
		long long ans=0;
		while(q.size()!=1)
		{
			long long a=q.top();
			q.pop();
			long long b=q.top();
			q.pop();
			ans+=a+b;
			q.push(a+b);
		}
		cout << ans << "\n";
	}
	return 0;
}