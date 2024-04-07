#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (auto c : s)
    {
        if (c == 'U')
            y++;
        else if (c == 'D')
            y--;
        else if (c == 'L')
            x--;
        else
            x++;
        if (x == 1 && y == 1)
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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