#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n >= 3)
        cout << "NO\n";
    else
    {
        if (n == 1 || s[0] != s[1])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

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