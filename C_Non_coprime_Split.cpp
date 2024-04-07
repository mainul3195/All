#include <bits/stdc++.h>
using namespace std;
#define lim 10000020
vector<long long> spf(lim + 1);
void smallest_pf()
{
    spf[1] = 1;
    for (long long i = 2; i <= lim; i += 2)
        spf[i] = 2;
    for (long long i = 3; i * i <= lim; i += 2)
        if (!spf[i])
            for (long long j = i; j <= lim; j += 2 * i)
                if (!spf[j])
                    spf[j] = i;
    for (int i = 3; i <= lim; i += 2)
        if (!spf[i])
            spf[i] = i;
    return;
}
void solve()
{
    int l, r;
    cin >> l >> r;
    for (int i = r; i >= l; i--)
        if (spf[i] != i)
        {
            cout << spf[i] << " " << i - spf[i] << "\n";
            return;
        }
    cout << "-1\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    smallest_pf();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}