#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    cout << n - (long long)sqrt(n + .05) - (long long)sqrt(n / 2 + .05) << "\n";
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