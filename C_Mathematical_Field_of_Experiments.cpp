#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int p;
    cin >> p;
    int ans[p + 1];
    memset(ans, -1, sizeof(ans));
    for (long long x = 0; x < p; x++)
        ans[(x * x) % p] = x;
    for (int i = 0; i < p; i++)
        cout << ans[i] << " ";
    cout << "\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}