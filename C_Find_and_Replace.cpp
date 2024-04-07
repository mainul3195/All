#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ar(26, 2);
    ar[s[0] - 'a'] = 0;
    for (int i = 1; i < n; i++)
    {
        if (ar[s[i] - 'a'] == ar[s[i - 1] - 'a'])
        {
            cout << "NO\n";
            return;
        }
        if (ar[s[i] - 'a'] == 2)
        {
            if (ar[s[i - 1] - 'a'] == 0)
                ar[s[i] - 'a'] = 1;
            else
                ar[s[i] - 'a'] = 0;
        }
    }
    cout << "YES\n";
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