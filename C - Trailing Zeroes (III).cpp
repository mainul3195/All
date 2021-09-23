#include<bits/stdc++.h>
using namespace std;
int zeroes(int n)
{
	int count=0;
	while(n)
	{
		count+=n/5;
		n/=5;
	}
	return count;
}
int main()
{
	int t;
	int i=0;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int ans=0,l=5, r=500000000, mid;
		while(l<=r)
		{
			mid=(l+r)/2;
			int count=zeroes(mid);
			if(count==n)
				ans=mid;
			if(count>=n)
				r=mid-1;
			else
				l=mid+1;
		}
		if(ans)
			cout << "Case " << ++i << ": " << ans << "\n";
		else
			cout << "Case " << ++i << ": " << "impossible\n";
	}
	return 0;
}
