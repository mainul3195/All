#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return (b * bigMod(b, p - 1));
    long long T = bigMod(b, p / 2);
    return (T * T);
}
void solve()
{
    cin >> n >> m;
    if (n <= 32)
        cout << m % bigMod(2, n) << "\n";
    else
        cout << m << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}