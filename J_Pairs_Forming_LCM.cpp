#include <bits/stdc++.h>
using namespace std;
#define lim 20000020
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
    long long ans = 1;
    return;
}
void solve()
{
    long long n;
    cin >> n;
    long long ans = 1;
    for (auto p : primes)
    {
        if (p * p > n)
            break;
        int count = 0;
        while (n % p == 0)
        {
            count++;
            n /= p;
        }
        ans *= (2 * count + 1);
    }
    if (n > 1)
        ans *= 3;
    cout << (ans + 1) / 2 << "\n";
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