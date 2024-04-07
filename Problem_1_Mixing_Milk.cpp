#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long cap[3], cur[3];
    for (int i = 0; i < 3; i++)
        cin >> cap[i] >> cur[i];
    for (int i = 0; i < 100; i++)
    {
        int u = i % 3;
        int v = (i + 1) % 3;
        long long tot = cur[u] + cur[v];
        cur[v] = min(cap[v], tot);
        cur[u] = tot - cur[v];
    }
    cout << cur[0] << "\n"
         << cur[1] << "\n"
         << cur[2] << "\n";
    return;
}
int main()
{
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}