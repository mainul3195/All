#include<bits/stdc++.h>
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
		int ans=0;
		for(int i=2; i*i <=n; i++)
		{
			int count=0;
			while(!(n%i))
			{
				count++;
				n/=i;
			}
			ans=max(count, ans);
		}
		if(n!=1)
			ans=max(ans, 1);
		cout << ans << "\n";
	}
	return 0;
}