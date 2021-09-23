#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin >> n && n)
	{
		priority_queue<int, vector<int>, greater<int> > q;
		for(int i=0; i<n; i++)
		{
			int j;
			cin >> j;
			q.push(j);
		}
		long long tot=0, sum=0;
		while(q.size()>1)
		{
			sum=q.top();
			q.pop();
			sum+=q.top();
			q.pop();
			tot+=sum;
			q.push(sum);
		}
		cout << tot << "\n";
	}
	return 0;
}