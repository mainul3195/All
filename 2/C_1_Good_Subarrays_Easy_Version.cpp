#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n), ans(n);
    for (auto &i : v)
        cin >> i;
    ans[0] = 1;
    for (int i = 1; i < n; i++)
        ans[i] = min(v[i] - 1, ans[i - 1]) + 1;
    long long tot = 0;
    for (auto i : ans)
        tot += i;
    cout << tot << "\n";
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