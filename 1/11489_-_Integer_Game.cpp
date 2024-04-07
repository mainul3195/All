#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int tot = 0, div3 = 0;
    for (auto i : s)
    {
        if ((i - '0') % 3 == 0)
            div3++;
        tot += i - '0';
    }
    bool found = 0;
    for (auto c : s)
        if ((tot - c + '0') % 3 == 0)
        {
            found = 1;
            break;
        }
    if ((tot % 3 == 0 && div3 % 2) || ((tot % 3) && found && ((div3 & 1) == 0)))
        cout << "S\n";
    else
        cout << "T\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}