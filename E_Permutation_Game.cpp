#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int inc = 1, dec = n, fc = 0, sc = 0, b = 0;
    for (auto i : v)
    {
        if (i != inc)
            fc++;
        if (i != dec)
            sc++;
        if (i != inc && i != dec)
            b++;
        inc++;
        dec--;
    }
    if (fc + b <= sc)
        cout << "First\n";
    else if (sc + b < fc)
        cout << "Second\n";
    else
        cout << "Tie\n";
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