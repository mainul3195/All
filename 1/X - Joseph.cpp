/**
    "If you have an apple and I have an apple and
    we exchange apples then you and I will still
    each have one apple. But if you have an idea
    and I have an idea and we exchange these
    ideas, then each of us will have two ideas."
                        -George Bernard Shaw
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>ans(14);
bool ok(int k, int m)
{
	int n=2*k, x=0;
	while(n>k)
	{
		x=(x+m-1)%n;
		if(x<k)
			return 0;
		n--;
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int k=1; k<14; k++)
		for(int m=k+1; ; m++)
			if(ok(k, m))
			{
				ans[k]=m;
				break;
			}
	int n;
	while(cin >> n && n)
		cout << ans[n] << "\n";
	return 0;
}