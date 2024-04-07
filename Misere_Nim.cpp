#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    bool all1 = 1;
    int Xor = 0;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        if (u > 1)
            all1 = 0;
        Xor ^= u;
    }
    if ((all1 && !Xor) || (!all1 && Xor))
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