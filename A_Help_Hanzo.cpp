#include <bits/stdc++.h>
using namespace std;
#define lim 100000020
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
    long long l, r;
    cin >> l >> r;
    bit.reset();
    for (auto p : primes)
    {
        if (p * p > r)
            break;
        long long start = (l + p - 1) / p * p;
        if (start == p)
            start += p;
        for (; start <= r; start += p)
            bit[start - l] = 1;
    }
    int count = 0;
    for (int i = l; i <= r; i++)
        if (!bit[i - l] && i != 1)
            count++;
    cout << count << "\n";
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