#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == 't' && s[i - 1] == 'i')
        {
            cout << "YES\n";
            return;
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