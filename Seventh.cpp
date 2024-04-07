#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    while (q--)
    {
        int t;
        cin >> t;
        if (t)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int count = 0;
            for (int i = l; i <= r; i++)
                if (!v[i])
                    count++;
            cout << count << "\n";
        }
        else
        {
            int l, r;
            long long e;
            cin >> l >> r >> e;
            l--, r--;
            for (int i = l; i <= r; i++)
                v[i] = max(v[i] - e, 0LL);
        }
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}