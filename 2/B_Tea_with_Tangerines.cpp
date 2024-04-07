#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int mn = 100000000, n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
        mn = min(i, mn);
    }
    mn = 2 * mn - 1;
    int cnt = 0;
    for (auto i : v)
        cnt += (i + mn - 1) / mn - 1;
    cout << cnt << "\n";
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