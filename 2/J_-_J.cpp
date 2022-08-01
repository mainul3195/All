#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n), y(m);
    for (auto &i : x)
        cin >> i;
    for (auto &i : y)
        cin >> i;

    vector<int> pref(m + 1, 0);
    for (int i = 0; i < m; i++)
        pref[i + 1] = pref[i] + y[i];

    for (int i = 0; i < n; i++)
    {
        int last = min(i + 1, m);
        int len = min({i + 1, m, n - i, n - m + 1});
        x[i] = (x[i] + pref[last] - pref[last - len]) % k;
    }

    for (auto i : x)
        cout << i << " ";
    cout << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}