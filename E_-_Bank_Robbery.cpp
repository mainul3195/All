#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    n % 9 ? cout << n + (n / 9) << "\n" : cout << n + (n - 1) / 9 << " " << n + n / 9 << "\n";
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