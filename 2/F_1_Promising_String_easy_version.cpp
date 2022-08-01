#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> plus(n + 1, 0), minus(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+')
            plus[i + 1]++;
        else
            minus[i + 1]++;
    }
    for (int i = 1; i <= n; i++)
    {
        plus[i] += plus[i - 1];
        minus[i] += minus[i - 1];
    }
    // for (auto i : plus)
    //     cout << i << " ";
    // cout << "\n";
    // for (auto i : minus)
    //     cout << i << " ";
    // cout << "\n";
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int dif = minus[j] - minus[i - 1] - plus[j] + plus[i - 1];
            // cout << dif << "\n";
            if (dif >= 0 && dif % 3 == 0)
                ans++;
        }
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