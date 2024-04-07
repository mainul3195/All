#include <bits/stdc++.h>
using namespace std;
int n, q;
void solve()
{
    cin >> n >> q;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        mp[l]++;
        mp[r + 1]--;
    }
    bool first = 1;
    int prev = 0;
    for (auto &[nm, val] : mp)
    {
        if (first)
        {
            first = 0;
            prev = val;
            continue;
        }
        val += prev;
        prev = val;
    }
    while (q--)
    {
        int x;
        cin >> x;
        auto it = mp.upper_bound(x);
        if (it == mp.begin())
            cout << "0\n";
        else
        {
            it--;
            cout << (*it).second << "\n";
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ":\n";
        solve();
    }
    return 0;
}