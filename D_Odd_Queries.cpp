#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<long long> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        v[i] += v[i - 1];
    long long tot_sum = v[n];
    while (q--)
    {
        long long l, r, k;
        cin >> l >> r >> k;
        long long new_sum = tot_sum - v[r] + v[l - 1] + k * (r - l + 1);
        if (new_sum & 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
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