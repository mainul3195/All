#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
    map<string, double> mp;
    long long tot = 0;
    while (getline(cin, s) && s.size())
        mp[s]++, tot++;
    for (auto [s, v] : mp)
        cout << fixed << setprecision(4) << s << " " << v / tot * 100 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    getline(cin, s);
    getline(cin, s);
    while (t--)
    {
        solve();
        if (t)
            cout << "\n";
    }
    return 0;
}