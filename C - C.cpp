#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		queue<pair<int,int> > q;
		priority_queue<int> pq;
		for(int i=0; i<n; i++)
		{
			int j;
			cin >> j;
			q.push({j,i});
			pq.push(j);
		}
		int count=0;
		pair<int, int> p;
		while(1)
		{
			p=q.front();
			if(p.first<pq.top())
			{
				q.pop();
				q.push(p);
			}
			else
			{
				count++;
				pq.pop();
				q.pop();
				if(p.second==m)
					break;
			}
		}
		cout << count << "\n";
	}
	return 0;
}