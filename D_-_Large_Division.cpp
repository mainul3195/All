#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    int d;
    cin >> s >> d;
    if (s[0] == '-')
        s.erase(s.begin());
    if (d < 0)
        d *= -1;
    int r = 0;
    for (auto c : s)
        r = (r * 10 + c - '0') % d;
    cout << (!r ? "divisible" : "not divisible") << "\n";
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