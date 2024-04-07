#include <bits/stdc++.h>
using namespace std;
int okdone(int n)
{
    if (n & 1)
        return -1;
    string s;
    while (n)
    {
        s.push_back('0' + n % 2);
        n >>= 1;
    }
    for (int i = 1; i < s.size(); i++)
        if (s[i] == '1' && s[i - 1] == '1')
            return -1;
    for (int i = 1; i < s.size(); i++)
        if (s[i] == '1')
            s[i - 1] = '1';
    int mul = 1;
    int num = 0;
    for (auto c : s)
    {
        if (c == '1')
            num += mul;
        mul <<= 1;
    }
    return num;
}
void solve()
{
    int n;
    cin >> n;
    int ans = okdone(n);
    if (ans == -1)
        cout << ans << "\n";
    else
        cout << ans << " " << 2 * n - ans << "\n";
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