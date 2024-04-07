#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    while (cin >> n)
    {
        n++;
        int lg = log2(n + .5);
        long long t = n - (1 << lg);
        cout << 2 * t + 1 << "\n";
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