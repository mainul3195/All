#include <bits/stdc++.h>
using namespace std;
#define lim 1000000
#define mod 1000000007
bitset<lim + 5> b;
vector<long long> primes;
void sieve()
{
    primes.push_back(2);
    for (int i = 3; i * i <= lim; i += 2)
        if (b[i] == 0)
            for (int j = i * i; j <= lim; j += 2 * i)
                b[j] = 1;
    for (int i = 3; i <= lim; i += 2)
        if (b[i] == 0)
            primes.push_back(i);
    return;
}
long long bigMod(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return b * bigMod(b, p - 1) % mod;
    long long t = bigMod(b, p / 2);
    return t * t % mod;
}
void solve()
{
    long long x, n;
    cin >> x >> n;
    long long tx = x;
    vector<long long> prime_divisors;
    for (auto p : primes)
    {
        if (p * p > x)
            break;
        if (x % p == 0)
            prime_divisors.push_back(p);
        while (x % p == 0)
            x /= p;
    }
    if (x != 1)
        prime_divisors.push_back(x);
    long long tn = n;
    long long ans = 1;
    for (auto d : prime_divisors)
    {
        tn = n;
        while (tn > 1)
        {
            long long times = tn / d;
            ans = ans * bigMod(d, times) % mod;
            tn /= d;
        }
    }
    cout << ans << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    solve();
    return 0;
}