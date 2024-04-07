#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int p, s, r;
    cin >> p >> s >> r;
    if(p==s && r!=1)
        cout << "No\n";
    else cout << "Yes\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}