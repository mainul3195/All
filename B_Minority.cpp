#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int oc = 0, zc = 0;
    for (auto i : s)
        (i == '0') ? zc++ : oc++;
    cout << min(oc, zc) - (oc == zc) << "\n";
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