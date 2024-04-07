#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (auto c : s)
    {
        if (c == ',')
            c = ' ';
        cout << c;
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}