#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long tot = 0;
    for (long long i = 2; i * i <= n; i++)
    {
        long long lim = n / i;
        tot += lim * (lim + 1) / 2 - i * (i - 1) / 2 + (lim - i) * i;
    }
    cout << tot << "\n";
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