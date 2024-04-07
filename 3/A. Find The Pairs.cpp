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
		int c=0;
		for(int i=n; i!=0; i/=2)
			if(i%2)
				c++;
		long long ans=1;
		for(int i=0; i<c; i++)
			ans*=3;
		cout << ans << "\n";
	}
	return 0;
}