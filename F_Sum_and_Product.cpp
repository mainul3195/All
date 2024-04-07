#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    map<int, long long> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        long long x, y;
        cin >> x >> y;
        long long d = x * x - 4 * y;
        if (d < 0)
        {
            cout << "0 ";
            continue;
        }
        if (d == 0)
        {
            if (x % 2 == 0)
            {
                long long a = x / 2;
                cout << mp[a] * (mp[a] - 1) / 2 << " ";
            }
            else
                cout << "0 ";
            continue;
        }
        long long sq = sqrt(d + .5);
        if (sq * sq != d)
        {
            cout << "0 ";
            continue;
        }
        int ai = x + sq;
        int aj = x - sq;
        if ((ai % 2) || (aj % 2))
        {
            cout << "0 ";
            continue;
        }
        cout << mp[ai / 2] * mp[aj / 2] << " ";
    }
    cout << "\n";
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