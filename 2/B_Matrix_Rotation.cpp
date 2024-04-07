#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> v(4);
    cin >> v[0] >> v[1] >> v[3] >> v[2];
    int t = 4;
    do
    {
        if (v[1] > v[0] && v[2] > v[1] && v[3] < v[2] && v[3] > v[0])
        {
            cout << "YES\n";
            return;
        }
        rotate(v.begin(), v.begin() + 1, v.end());
    } while (t--);
    cout << "NO\n";
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