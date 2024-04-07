#include <bits/stdc++.h>
using namespace std;
#define mod 100000007
void solve()
{
    int tc = 0;
    long long n, m, t;
    while (cin >> n >> m >> t && (n || m))
    {
        long long ans1 = 1, ans2 = 1;
        for (long long i = 2; i * i <= n; i++)
        {
            int count = 0;
            while (n % i == 0)
            {
                n /= i;
                count++;
            }
            count *= m;
            if (count)
            {
                ans1 = ans1 * (count / t + 1) % mod;
                ans2 = ans2 * (count / (t + 1) + 1) % mod;
            }
        }
        if (n != 1)
        {
            ans1 = ans1 * (m / t + 1) % mod;
            ans2 = ans2 * (m / (t + 1) + 1) % mod;
        }
        cout << "Case " << ++tc << ": " << (ans1 - ans2 + mod) % mod << "\n";
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