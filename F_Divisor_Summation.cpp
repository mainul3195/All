#include <bits/stdc++.h>
using namespace std;
#define lim 100000050
vector<long long> primes;
bitset<lim / 2 + 2> bit;
void sieve()
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
void solve()
{
    long long n;
    cin >> n;
    long long tmp = n;
    long long sod = 1;
    for (auto p : primes)
    {
        if (p * p > n)
            break;
        long long mul = p;
        while (n % p == 0)
        {
            mul *= p;
            n /= p;
        }
        sod *= ((mul - 1) / (p - 1));
    }
    if (n != 1)
        sod *= (n + 1);
    cout << sod - tmp << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}