/**
    "If you have an apple and I have an apple and
    we exchange apples then you and I will still
    each have one apple. But if you have an idea
    and I have an idea and we exchange these
    ideas, then each of us will have two ideas."
                        -George Bernard Shaw
*/

#include<bits/stdc++.h>
using namespace std;
void frontt(deque<int>&que)
{
	if(que.empty())
		cout << "No job for Ada?\n";
	else
	{
		cout << que.front() << "\n";
		que.pop_front();
	}
}
void backk(deque<int>&que)
{
	if(que.empty())
		cout << "No job for Ada?\n";
	else
	{
		cout << que.back() << "\n";
		que.pop_back();
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	deque<int> que;
	string s; 
	int n;
	bool ok=1;
	while(q--)
	{
		cin >> s;
		if(s=="back")
		{
			if(ok)
				backk(que);
			else
				frontt(que);
		}
		else if(s=="front")
		{
			if(ok)
				frontt(que);
			else
				backk(que);
		}
		else if(s=="reverse")
			ok=!ok;
		else if(s=="push_back")
		{
			cin >> n;
			if(ok)
				que.push_back(n);
			else
				que.push_front(n);
		}
		else if(s=="toFront")
		{
			cin >> n;
			if(ok)
				que.push_front(n);
			else
				que.push_back(n);
		}	
	}
	return 0;
}