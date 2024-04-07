#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    long long tmp = bigMod(b, p / 2);
    tmp = tmp * tmp % mod;
    if (p & 1)
        tmp = tmp * b % mod;
    return tmp;
}
void solve()
{
    int q;
    cin >> q;
    queue<pair<long long, long long>> que;
    long long c1 = 1, c2 = 0;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            c1 = c1 * bigMod(que.front().first, mod - 2) % mod;
            c2 = (c2 - que.front().second * c1 % mod + mod) % mod;
            que.pop();
        }
        else if (t == 2)
        {
            long long x;
            cin >> x;
            cout << (c1 * x + c2) % mod << "\n";
        }
        else
        {
            int a, b;
            cin >> a >> b;
            que.push({a, b});
            c1 = c1 * a % mod;
            c2 = (c2 * a + b) % mod;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}