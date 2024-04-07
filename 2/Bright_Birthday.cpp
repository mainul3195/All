#include <bits/stdc++.h>
using namespace std;
vector<string> colors = {"blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black"};
void solve()
{
    string s;
    cin >> s;
    vector<int> ar(26, 0);
    for (auto c : s)
        ar[c - 'a']++;
    int cnt = 0;
    int lim = (1 << 15) - 1;
    for (int i = 0; i <= lim; i++)
    {
        vector<string> combs;
        for (int j = 0; j < 15; j++)
            if (i & (1 << j))
                combs.push_back(colors[j]);
        vector<int> tmp = ar;
        for (auto str : combs)
            for (auto c : str)
                tmp[c - 'a']--;
        bool ok = 1;
        for (int i = 0; i < 26; i++)
            if (tmp[i] < 0)
            {
                ok = 0;
                break;
            }
        if (ok)
            cnt = max(cnt, (int)combs.size());
    }
    cout << cnt << "\n";
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