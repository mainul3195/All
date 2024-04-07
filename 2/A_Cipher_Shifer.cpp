#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    string ans;
    char c = -1;
    for (auto i : s)
    {
        if (c == -1)
        {
            c = i;
            continue;
        }
        if (i == c)
        {
            ans.push_back(i);
            c = -1;
        }
    }
    cout << ans << "\n";
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