#include <bits/stdc++.h>
using namespace std;
int diff(int ar[26])
{
    int count = 0;
    for (int i = 0; i < 26; i++)
        if (ar[i])
            count++;
    return count;
}
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    int f[26] = {0}, r[26] = {0};
    for (auto c : s)
        r[c - 'a']++;
    int ans = diff(r);
    for (int i = 0; i < n; i++)
    {
        r[s[i] - 'a']--;
        f[s[i] - 'a']++;
        ans = max(ans, diff(f) + diff(r));
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