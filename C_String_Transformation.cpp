#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    vector<int> v1, v2;
    map<char, int> mp;
    int st = 0;
    for (auto c : s)
    {
        if (mp.find(c) == mp.end())
            mp[c] = ++st;
        v1.push_back(mp[c]);
    }
    mp.clear();
    st = 0;
    for (auto c : t)
    {
        if (mp.find(c) == mp.end())
            mp[c] = ++st;
        v2.push_back(mp[c]);
    }
    if (v1 == v2)
        cout << "Yes\n";
    else
        cout << "No\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}