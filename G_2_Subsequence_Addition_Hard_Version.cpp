#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> c(n);
    for (auto &i : c)
        cin >> i;
    sort(c.begin(), c.end());
    if (c[0] != 1)
    {
        cout << "NO\n";
        return;
    }
    long long last = 1;
    for (int i = 1; i < n; i++)
    {
        if (c[i] > last)
        {
            cout << "NO\n";
            return;
        }
        last += c[i];
    }
    cout << "YES\n";
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