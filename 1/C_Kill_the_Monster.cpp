#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long hc, dc, hm, dm, k, w, a;
    cin >> hc >> dc >> hm >> dm >> k >> w >> a;
    bool ok = 0;
    for (int i = 0; i <= k; i++)
        if ((hm + dc + i * w - 1) / (dc + i * w) <= (hc + (k - i) * a + dm - 1) / dm)
        {
            ok = 1;
            break;
        }
    cout << (ok ? "YES" : "NO") << "\n";

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