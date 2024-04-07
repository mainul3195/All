#include <bits/stdc++.h>
using namespace std;
bitset<50000004> m;
vector<long long> primes;
long long Pow(long long b, long long p)
{
    if (!p)
        return 1;
    if (p & 1)
        return b * Pow(b, p - 1);
    long long tmp = Pow(b, p / 2);
    return tmp * tmp;
}
void sieve()
{
    for (int i = 3; i * i <= 100000000; i += 2)
        if (m[i / 2] == 0)
            for (int j = i * i; j <= 100000000; j += 2 * i)
                m[j / 2] = 1;
    primes.push_back(2);
    for (int i = 3; i <= 100000000; i += 2)
        if (m[i / 2] == 0)
            primes.push_back(i);
    primes.push_back(100000007);
    return;
}
void solve()
{
    long long n;
    cin >> n;
    long long str = n;
    long long ans = 1;
    for (auto p : primes)
    {
        if (p * p > n)
            break;
        long long count = 1;
        while (n % p == 0)
        {
            count++;
            n /= p;
        }
        ans *= (Pow(p, count) - 1) / (p - 1);
    }
    if (n != 1)
        ans *= (n + 1);
    cout << ans - str << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    sieve();
    cin >> t;
    while (t--)
        solve();
    return 0;
}