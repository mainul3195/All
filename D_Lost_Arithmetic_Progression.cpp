#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
// complexity: O(log(max(a,b)))
long long gcd(long long a, long long b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
void solve()
{
    long long b, q, y, c, r, z;
    cin >> b >> q >> y >> c >> r >> z;

    // zero test
    long long b1 = b, bn = b + (y - 1) * q;
    long long c1 = c, cn = c + (z - 1) * r;
    if (cn > bn || c1 < b1 || (c1 - b1) % q != 0 || (bn - cn) % q != 0 || (r % q != 0 && (cn - r > b1 || c1 + r < bn)))
    {
        cout << "0\n";
        return;
    }

    // infinity test
    if (c1 - r < b1 || cn + r > bn)
    {
        cout << "-1\n";
        return;
    }
    vector<long long> da;
    for (long long i = 1; i * i <= r; i++)
    {
        if (r % i == 0)
        {
            da.push_back(i);
            if (i != r / i)
                da.push_back(r / i);
        }
    }
    long long ans = 0;
    for (auto p : da)
    {
        // cout << p << "\n";
        if (lcm(p, q) == r)
            ans = (ans + ((r / p) * (r / p)) % mod) % mod;
    }
    cout << ans << "\n";

    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}