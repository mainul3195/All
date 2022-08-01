#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(31, 0);
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        int ind = 0;
        while (u)
        {
            if (u & 1)
                v[ind]++;
            u >>= 1;
            ind++;
        }
    }
    for (int i = 30; k && i >= 0; i--)
    {
        if (v[i] < n && n - v[i] <= k)
        {
            k -= (n - v[i]);
            v[i] = n;
        }
    }
    int mul = 1, ans = 0;
    for (int i = 0; i <= 30; i++, mul *= 2)
    {
        if (v[i] == n)
            ans += mul;
    }
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