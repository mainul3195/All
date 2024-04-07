#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    long long Xor = 0;
    int tmp = (n + m) % 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            long long x;
            cin >> x;
            if (tmp != (i + j) % 2)
                Xor ^= x;
        }
    if (Xor)
        cout << "win\n";
    else
        cout << "lose\n";
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