#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    vector<vector<int>> v(k);
    for (int i = s.size() - 1; i >= 0; i--)
        v[s[i] - 'a'].push_back(i);
    int last_pos;
    string ans;
    for (int i = 0; i < n; i++)
    {
        int tmp_max = -1;
        for (int j = 0; j < k; j++)
        {
            if (v[j].empty())
            {
                cout << "NO\n";
                cout << ans;
                for (int l = i; l < n; l++)
                    cout << (char)(j + 'a');
                cout << "\n";
                return;
            }
            tmp_max = max(tmp_max, v[j].back());
            v[j].pop_back();
        }
        last_pos = tmp_max;
        ans += s[last_pos];
        for (int j = 0; j < k; j++)
            while (v[j].size() && v[j].back() < last_pos)
                v[j].pop_back();
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