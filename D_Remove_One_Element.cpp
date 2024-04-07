#include <bits/stdc++.h>
using namespace std;
vector<int> a, u, v;
void solve()
{
    int n;
    cin >> n;
    a = u = v = vector<int>(n + 1);
    a[0] = 2000000000;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    u[1] = v[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i - 1])
        {
            if (a[i] > a[i - 2] && a[i - 1] <= a[i - 2])
            {
                v[i] = v[i - 1] + 1;
                u[i] = v[i - 2] + 1;
            }
            else
                u[i] = u[i - 1] + 1, v[i] = v[i - 1] + 1;
        }
        else
        {
            v[i] = 1;
            u[i] = a[i - 2] < a[i] ? v[i - 1] : 1;
        }
    }
    // for (int i = 1; i <= n; i++)
    //     cout << v[i] << " ";
    // cout << "\n";
    // for (int i = 1; i <= n; i++)
    //     cout << u[i] << " ";
    // cout << "\n";
    int mx = 0;
    for (int i = 1; i <= n; i++)
        mx = max({mx, v[i], u[i]});
    cout << mx << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}