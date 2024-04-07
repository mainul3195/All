#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int i = 0;
    bool ok = 1;
    while (i < s.size())
    {
        int count = 0;
        char c = s[i];
        while (i < s.size() && s[i] == c)
        {
            count++;
            i++;
        }
        if (count == 1)
        {
            ok = 0;
            break;
        }
    }
    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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