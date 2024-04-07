#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        for (auto i : v)
        {
            if (i == a)
            {
                cout << a << "\n";
                break;
            }
            if (i == b)
            {
                cout << b << "\n";
                break;
            }
        }
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