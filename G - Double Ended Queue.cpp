#include<bits/stdc++.h>
using namespace std;
int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int t,j=0;
	cin >> t;
	while(t--)
	{
		cout << "Case " << ++j << ":\n";
		deque<int>q;
		int n , m;
		cin >> n >> m;
		while(m--)
		{
			string s;
			int x;
			cin >> s;
			if(s=="pushLeft")
			{
				int i;
				cin >> i;
				if(q.size()<n)
				{
					q.push_front(i);
					cout << "Pushed in left: " << i << "\n";
				}
				else
					cout << "The queue is full\n";
			}
			else if(s=="pushRight")
			{
				int i;
				cin >> i;
				if(q.size()<n)
				{
					q.push_back(i);
					cout << "Pushed in right: " << i << "\n";
				}
				else
					cout << "The queue is full\n";
			}
			else if(s=="popLeft")
			{
				if(q.empty())
					cout << "The queue is empty\n";
				else
				{
					int i=q.front();
					q.pop_front();
					cout << "Popped from left: " << i << "\n";
				}
			}
			else if(s=="popRight")
			{
				if(q.empty())
					cout << "The queue is empty\n";
				else
				{
					int i=q.back();
					q.pop_back();
					cout << "Popped from right: " << i << "\n";
				}
			}
		}
	}
	return 0;
}