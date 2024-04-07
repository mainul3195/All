#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        int a, b;
        cin >> a >> b;
        cout << abs(a - b) << "\n";
    }
    else
    {
        long long mx = -1e18, mn = 1e18;
        long long dif0 = 0, dif2 = 0;
        vector<long long> v;
        int lim = 2 * n;
        for (int i = 0; i < lim; i++)
        {
            long long a;
            cin >> a;
            dif0 += abs(a);
            dif2 += abs(a - 2);
            if (a > mx)
                mx = a;
            if (a < mn)
                mn = a;
            v.push_back(a);
        }
        long long tot_1 = 0;
        for (int i = 0; i < v.size(); i++)
            tot_1 += abs(v[i] + 1);
        if (n == 2)
            dif0 = min(dif0, dif2);
        if (n & 1)
            tot_1 = 10000000000000000;
        // cout << dif0 << " " << tot_1 << " " << tot_1 - abs(mx + 1) + abs(n - mx) << " " << tot_1 - abs(mn + 1) + abs(n - mn) << "\n";
        cout << min({dif0, tot_1 - abs(mx + 1) + abs(n - mx), tot_1 - abs(mn + 1) + abs(n - mn)}) << "\n";
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