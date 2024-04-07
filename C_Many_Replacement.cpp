#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    map<char, char> mp;
    for (int i = 0; i < 26; i++)
        mp[(char)(i + 'a')] = (char)(i + 'a');
    while (q--)
    {
        char a, b;
        cin >> a >> b;
        for (auto &[p, q] : mp)
            if (q == a)
                q = b;
    }
    for (auto c : s)
        cout << mp[c];
    cout << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}