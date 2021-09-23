#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> q;
	while(q--)
	{
		long long n,k;
		cin >> n >> k;
		double d=(sqrt(1+8*k)-1)/2.0;
		long long f=ceil(d), g;
		g=f-1;
		long long l=(g*(g+1))/2;
		l=k-l-1;
		//cout << g << " " << l << "\n";
		char s[n+1];
		s[n]=0;
		for(long long i=0; i<n; i++)
		{
			if(i==l || i==f)
				s[i]='b';
			else
				s[i]='a';
		}
		reverse(s, s+n);
		cout << s << "\n";
	}
	return 0;
}