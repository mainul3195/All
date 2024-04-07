#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    int pow = 0;
    while (1ll << pow <= n)
        pow++;
    cout << ((n * (n + 1) >> 1) - (((1ll << pow) - 1) << 1)) << "\n";
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