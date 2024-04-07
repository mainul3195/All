#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x;
    cin >> n >> x;
    cout << 3 * (n - __gcd(n, x));
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}