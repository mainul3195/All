#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int zcnt = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (!a)
            zcnt++;
        if (a > mx)
            mx = a;
    }
    if (zcnt - 1 <= n - zcnt)
        cout << "0\n";
    else
    {
        if (mx != 1)
            cout << "1\n";
        else
            cout << "2\n";
    }
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