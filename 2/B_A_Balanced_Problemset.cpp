#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, n;
    cin >> x >> n;
    int lim = sqrt(x + .5);
    vector<int> divs;
    for (int i = 1; i <= lim; i++)
        if (x % i == 0)
        {
            divs.push_back(i);
            if (i != x / i)
                divs.push_back(x / i);
        }
    sort(divs.begin(), divs.end());
    int ans = 1;
    for (auto i : divs)
    {
        if ((long long)i * n <= x)
            ans = i;
        else
            break;
    }
    cout << ans << "\n";
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