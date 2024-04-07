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
void solve()
{
    long long n;
    cin >> n;
    bool minus = n < 0;
    if (minus)
        n *= -1;
    map<long long, long long> mp;
    for (auto p : primes)
    {
        if (p * p > n)
            break;
        int count = 0;
        while (!(n % p))
        {
            count++;
            n /= p;
        }
        if (count)
            mp[p] = count;
    }
    if (n > 1)
        mp[n] = 1;
    long long g = 0;
    for (auto [_, c] : mp)
        g = __gcd(g, c);
    if (g == 1 || !minus)
        cout << g << "\n";
    else
    {
        while (!(g % 2))
            g /= 2;
        cout << g << "\n";
    }
    return;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    make_primes();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}