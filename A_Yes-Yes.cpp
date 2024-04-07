#include <bits/stdc++.h>
using namespace std;
string mn = "Yes";
void solve()
{
    string s;
    cin >> s;
    int start;
    if (s[0] == 'Y')
        start = 0;
    else if (s[0] == 'e')
        start = 1;
    else if (s[0] == 's')
        start = 2;
    else
    {
        cout << "NO\n";
        return;
    }
    for (auto c : s)
    {
        if (c != mn[start])
        {
            cout << "NO\n";
            return;
        }
        start = (start + 1) % 3;
    }
    cout << "YES\n";
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