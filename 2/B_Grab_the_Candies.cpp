#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x & 1)
            odd += x;
        else
            even += x;
    }
    if (even > odd)
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}