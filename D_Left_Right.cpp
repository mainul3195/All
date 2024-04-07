#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    n <<= 1;
    int prev;
    int Xor = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i & 1)
            Xor ^= (x - prev - 1);
        prev = x;
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