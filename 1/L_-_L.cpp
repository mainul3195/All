#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long count = 0, mul = 1;
    while (mul * 2 <= n)
        mul <<= 1;
    // cout << mul << "\n";
    if (mul == n)
    {
        cout << log2(n) << "\n";
        return;
    }
    while (n != 1)
    {
        n -= min(mul, n - 1);
        mul >>= 1;
        count++;
    }
    cout << count << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;
    // cin >> t;
    // while(t--)
    solve();
    return 0;
}