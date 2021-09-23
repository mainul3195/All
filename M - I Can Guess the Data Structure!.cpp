#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin>>n)
	{
		stack<int> stk;
		queue<int> que;
		priority_queue<int> pq;
		int op, val;
		bool s=1,q=1,p=1;
		while(n--)
		{
			cin >> op >> val;
			if(op==1)
			{
				if(s)
					stk.push(val);
				if(q)
					que.push(val);
				if(p)
					pq.push(val);
			}
			else
			{
				if(s)
				{
					if(!stk.empty() && stk.top()==val)
						stk.pop();
					else
						s=0;					
				}
				if(q)
				{
					if(!que.empty() && que.front()==val)
						que.pop();
					else
						q=0;
				}
				if(p)
				{
					if(!pq.empty() && pq.top()==val)
						pq.pop();
					else
						p=0;
				}
			}
		}
		if(s && !q && !p)
			cout << "stack\n";
		else if(!s && q && !p)
			cout << "queue\n";
		else if(!s && !q && p)
			cout << "priority queue\n";
		else if(s || q || q)
			cout << "not sure\n";
		else
			cout << "impossible\n";
	}
	return 0;
}