#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long m, r;
    int n;
    cin >> m >> r >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int cnt = 1;
    long long prev_s = 0, prev_e = 0, s_prev_e = 0;
    for (int i = 0; i < v.size(); i++)
    {
        long long x = v[i];
        if (x - r > prev_e)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        if (x - r > s_prev_e)
        {
            cnt++;
            s_prev_e = prev_e;
            prev_e = min(m, x + r);
            prev_s = max(0LL, x-r);
        }
        else
        {
            prev_s = max(0LL, x-r);
            prev_e = min(m, x + r);
        }
        if (prev_e == m)
        {
            cout << cnt << "\n";
            return;
        }
    }
    cout << "IMPOSSIBLE\n";

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