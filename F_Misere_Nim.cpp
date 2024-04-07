#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int Xor = 0;
    bool all_one = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Xor ^= x;
        if (x > 1)
            all_one = 0;
    }
    if (all_one)
    {
        if (n & 1)
            cout << "Bob\n";
        else
            cout << "Alice\n";
        return;
    }
    if (Xor)
        cout << "Alice\n";
    else
        cout << "Bob\n";
    return;
}
int32_t main()
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