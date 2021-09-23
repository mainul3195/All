#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin >> q;
	while(q--)
	{
		int n,m, mnt=0,flag=1,t, l, h;
		cin >> n >> m;
		int mx=m, mn=m;
		while(n--)
		{
			cin >> t >> l >> h;	
			if(!flag)
			continue;	
			if(mn-t+mnt>h || mx+t-mnt<l)
			{
				flag = 0;
				//cout << mn << " " << mx << " " << t << " " << l << " " << h << " " << n << "\n";
				continue;
			}
			mn=max(mn-t+mnt, l);
			mx=min(mx+t-mnt, h);
			//cout << mx << "\n";
			mnt=t;
		}
		if(flag)
			cout << "YES\n";
		else 
			cout << "NO\n";		
	}
	return 0;
}