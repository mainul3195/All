#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--)
        if (s[i] == s[j])
            break;
    cout << max(0, j - i + 1) << "\n";
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