// #include<bits/stdc++.h>
// using namespace std;

// void solve()
// {
//     int n, init, lt = 0;
//     cin >> n >> init;
//     int mn, mx;
//     mn = mx = init;
//     bool ok = 1;
//     while(n--)
//     {
//         int t, l, r;
//         cin >> t >> l >> r;
//         if(!ok)continue;
//         mn = mn - t + lt;
//         mx = mx + t - lt;
//         lt = t;
//         if(r<mn || l>mx)
//         {
//             ok = 0;
//             continue;
//         }
//         mn = max(mn, l);
//         mx = min(mx, r);
//     }
//     if(ok)
//         cout << "YES\n";
//     else cout << "NO\n";
//     return;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0); cin.tie(0);
//     int t = 1;
//     cin >> t;
//     while(t--)
//         solve(); 
//     return 0;
// }

// /*
// gcd
// lcm
// modfact
// fact
// pfsingle
// pfmultiple
// ncrsingle
// ncrmod
// bgmod
// mdinverse
// sieve
// SegmentTree
// kmp
// bit
// sparseTable
// vll
// pi
// ll
// Pair
// all
// mll
// mii
// mis
// msi
// vvi
// vi
// pb
// inf
// linf
// */

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
				continue;
			}
			mn=max(mn-t+mnt, l);
			mx=min(mx+t-mnt, h);
			mnt=t;
		}
		if(flag)
			cout << "YES\n";
		else 
			cout << "NO\n";		
	}
	return 0;
}