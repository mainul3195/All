#include <bits/stdc++.h>
using namespace std;
int n, k;
int dp[190][1150][16];
vector<long long> primes;
#define lim 1000006
bitset<lim / 2 + 1> f;
void sieve()
{
    primes.push_back(2);
    for (int i = 3; i * i <= lim; i += 2)
        if (!f[i / 2])
            for (int j = i * i; j <= lim; j += 2 * i)
                f[j / 2] = 1;
    for (int i = 3; i <= lim; i += 2)
        if (!f[i / 2])
            primes.push_back(i);
    return;
}
long long okdone(int i = 0, int rem = n, int taken = 0)
{
    if (taken == k && !rem)
        return dp[i][rem][taken] = 1;
    if (taken == k || !rem)
        return dp[i][rem][taken] = 0;
    if (primes[i] > rem)
        return 0;
    if (~dp[i][rem][taken])
        return dp[i][rem][taken];
    return dp[i][rem][taken] = okdone(i + 1, rem, taken) + okdone(i + 1, rem - primes[i], taken + 1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    memset(dp, -1, sizeof(dp));
    while (cin >> n >> k && (n || k))
        cout << okdone() << "\n";
    return 0;
}