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
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		vector<int>v(101, 0);
		int n;
		cin >> n;
		for(int i=0; i<n; i++)
		{
			int j;
			cin >> j;
			v[j]++;
		}
		int sum=0;
		for(int i=0; i<101; i++)
			if(!v[i])
			{
				sum+=i;
				v[i]++;
				break;
			}
		for(int i=0; i<101; i++)
			if(v[i]==1)
			{
				sum+=i;
				break;
			}
		cout << sum << "\n";
	}
	return 0;
}