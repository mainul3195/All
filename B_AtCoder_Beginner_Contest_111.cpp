#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    if (s[0] >= s[1] && s[0] >= s[2])
        cout << s[0] << s[0] << s[0];

    else
    {
        s[0]++;
        cout << s[0] << s[0] << s[0];
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}