#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &i : v)
        cin >> i;
    long long ans = 0;
    bool ok = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (ok && v[i] >= v[i + 1])
        {
            if (v[i] == 0 && v[i] == v[i + 1])
            {
                ok = !ok;
                break;
            }
            v[i] >>= 1;
            ans++;
        }
    }
    if (ok)
        cout << ans << "\n";
    else
        cout << "-1\n";
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