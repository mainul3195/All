#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int m, n;
    cin >> m >> n;
    int Xor = 0;
    long long tot;
    for (int i = 0; i < m; i++)
    {
        tot = 0;
        for (int j = 0; j < n; j++)
        {
            int u;
            cin >> u;
            tot += u;
        }
        Xor ^= tot;
    }
    if (Xor)
        cout << "Alice\n";
    else
        cout << "Bob\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}