#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n - 1));
    for (auto &vec : v)
        for (auto &el : vec)
            cin >> el;
    int ind, frst;
    for (int i = 0; i < n; i++)
    {
        int a = v[i][0];
        int b = v[(i + 1) % n][0];
        int c = v[(i + 2) % n][0];
        if (b == c && a != b)
        {
            frst = b;
            ind = i;
            break;
        }
    }
    cout << frst << " ";
    for (auto i : v[ind])
        cout << i << " ";
    cout << "\n";
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