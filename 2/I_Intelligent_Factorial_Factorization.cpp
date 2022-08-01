#include <bits/stdc++.h>
using namespace std;
int prime[] = {
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
    101};
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for (auto p : prime)
    {
        if (p > n)
            break;
        int tm = n;
        int tot = 0;
        while (tm)
        {
            tot += tm / p;
            tm /= p;
        }
        v.push_back({p, tot});
    }
    cout << n << " = ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " (" << v[i].second << ")";
        if (i == v.size() - 1)
            cout << "\n";
        else
            cout << " * ";
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
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}