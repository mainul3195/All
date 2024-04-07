#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    cout << a << "\n"
         << b << "\n";
    for (int i = 0; i < a.size(); i++)
        cout << (a[i] == b[i] ? '.' : '*');
    cout << "\n\n";

    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}