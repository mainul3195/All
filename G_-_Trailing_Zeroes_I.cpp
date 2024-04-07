#include <bits/stdc++.h>
using namespace std;
#define changeBit(i) (f[(i) / 32] |= (1 << ((i) % 32)))
#define checkBit(i) (f[(i) / 32] & (1 << ((i) % 32)))
#define lim 10000000
int f[lim / 32 + 1];
vector<long long> primes;
void sieve()
{
    for (int i = 4; i <= lim; i += 2)
        changeBit(i);
    for (int i = 3; i * i <= lim; i += 2)
        if (!checkBit(i))
            for (int j = i * i; j <= lim; j += 2 * i)
                changeBit(j);
    for (int i = 2; i <= lim; i++)
        if (!checkBit(i))
            primes.push_back(i);
}
int number_of_divisors(long long n)
{
    int tot = 1;
    for (auto i : primes)
    {
        if (i * i > n)
            break;
        int count = 0;
        while (!(n % i))
        {
            count++;
            n /= i;
        }
        tot *= (count + 1);
    }
    if (n > 1)
        tot *= 2;
    return tot;
}
void solve()
{
    long long n;
    cin >> n;
    cout << number_of_divisors(n) - 1 << "\n";
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        solve();
    }
    return 0;
}