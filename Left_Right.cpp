#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int Xor = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        Xor ^= (b - a - 1);
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