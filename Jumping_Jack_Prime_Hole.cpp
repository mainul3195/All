#include <bits/stdc++.h>
using namespace std;
#define lim 1000020
bitset<lim / 2 + 2> bit;
vector<long long> primes;
void make_primes()
{
    primes.push_back(2);
    for (int i = 3; i * i < lim; i += 2)
        if (!bit[i / 2])
            for (int j = i * i; j < lim; j += 2 * i)
                bit[j / 2] = 1;
    for (int i = 3; i < lim; i += 2)
        if (!bit[i / 2])
            primes.push_back(i);
    return;
}
int n, m;
vector<long long> dp;
#define mod 1000000007
long long okdone(int i)
{
    // cout << i << endl;
    if (i >= n)
        return i == n || i == n + 1;
    if (~dp[i])
        return dp[i];
    long long tot = okdone(i + 1);
    for (int j = 0; (i + primes[j] <= n) && (primes[j] < m); j++)
    {
        // cout << i << " " << j << " " << i+primes[j] << " " << primes[j] << " " << m  << endl;
        tot = (tot + okdone(i + primes[j] + 1)) % mod;
    }
    return dp[i] = tot;
}
void solve()
{
    cin >> n >> m;
    dp = vector<long long>(n + 3, -1);
    // cout << "here\n";
    cout << okdone(0) << "\n";
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_primes();
    // for (int i = 0; i < 20; i++)
    //     cout << primes[i] << " ";
    // cout << "\n";
    // cout << upper_bound(primes.begin(), primes.end(), 5000) - primes.begin() << "\n";
    // long long sum = 0;
    // for (int i = 0; i < 669; i++)
    //     sum += primes[i];
    // cout << sum << "\n";
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}