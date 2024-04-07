#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> d(26);
    for (auto &i : d)
        cin >> i;
    map<string, bool> mp;
    int n;
    cin >> n;
    bool done = 0;
    while (n--)
    {
        string s;
        cin >> s;
        if (done)
            continue;
        long long nm = 0;
        for (auto &c : s)
            c = d[c - 'A'] + '0';
        if (mp.count(s))
        {
            cout << "YES\n";
            done = 1;
        }
        mp[s] = 1;
    }
    if (!done)
        cout << "NO\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++tc << ": ";
        solve();
    }
    return 0;
}