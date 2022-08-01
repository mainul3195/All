#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> zeros(n + 2, 0), ones(n + 2, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zeros[i + 1]++;
        else if (s[i] == '1')
            ones[i + 1]++;
    }
    for (int i = 1; i < n + 2; i++)
        zeros[i] += zeros[i - 1];
    for (int i = n; i >= 0; i--)
        ones[i] += ones[i + 1];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (zeros[i - 1] == 0 && ones[i + 1] == 0)
            ans++;
    cout << ans << "\n";
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