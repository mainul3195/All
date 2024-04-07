#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    cout << n * (n - 1) / 2 << "\n";
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