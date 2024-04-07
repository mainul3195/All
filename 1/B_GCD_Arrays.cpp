#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, k;
    cin >> a >> b >> k;
    if (a == b)
    {
        cout << (a != 1 ? "YES" : "NO") << "\n";
        return;
    }
    long long tot = b - a + 1, odd;
    if (tot % 2)
    {
        if (a % 2)
            odd = tot / 2 + 1;
        else
            odd = tot / 2;
    }
    else
        odd = tot / 2;
    cout << (odd <= k ? "YES" : "NO") << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}