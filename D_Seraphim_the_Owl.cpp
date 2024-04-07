#include <bits/stdc++.h>
using namespace std;

vector<long long> a, b;
int n, m;

void solve()
{
    cin >> n >> m;
    a = b = vector<long long>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    long long ans = a[m];
    long long sm = b[m];
    for(int i = m-1; i; i--)
    {
        ans = min(ans, a[i]+sm);
        sm += b[i];
    }
    for (int i = n; i; i--)
    {
        if (i == m)
            break;
        ans += min(a[i], b[i]);
    }
    cout << ans << "\n";
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