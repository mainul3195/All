#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long ans = 0, len = 0, s = 0, e = 0, t;
    vector<long long> tm(n), hl(n);
    for (auto &i : tm)
        cin >> i;
    for (auto &i : hl)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        t = tm[i] - hl[i] + 1;
        // cout << t << " ";
        if (t <= e)
        {
            len += tm[i] - e;
            e = hl[i];
        }
        else
        {
            ans += len * (len + 1) / 2;
            len = tm[i] - t + 1;
            e = tm[i];
        }
        // cout << len << " ";
    }
    if (len)
        ans += len * (len + 1) / 2;
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}